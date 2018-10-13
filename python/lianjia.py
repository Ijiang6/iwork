# -*- coding: gbk -*-
from bs4 import BeautifulSoup
import requests
import csv
from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Polygon
import time
#one Page
#http://esf.cdfgj.gov.cn/search?page=1&qy=510109
mhedders={'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0'}
lats=[]
lons =[]
labels=[]
def draw_data_map():
    my_map=Basemap(projection='merc',lat_0=30.40,lon_0=104.04,resolution = 'l',
        area_thresh = 1000.0,
        llcrnrlon =97.21,llcrnrlat =26.03,
        urcrnrlon =108.31,urcrnrlat =34.19)
    my_map.readshapefile("/home/hacker/map/CHN_adm_shp/CHN_adm2",'Dìjíshì',drawbounds=True)
    my_map.drawcoastlines()
  #  my_map.shadedrelief()
    my_map.drawcounties()
    #my_map.etopo()
   # lats=[30.4,30.82,31.52]
   # lons=[104.04,108.40,117.17]
    x,y = my_map(lons, lats)
    my_map.plot(x, y, 'bo', markersize=6)
    #labels = ['chengdu', 'wanzhou','hefei' ]
    for label, xpt, ypt in zip(labels, x, y):
        plt.text(xpt+10000, ypt+500, label)

    plt.show()
def open_one_page(url):
#    mhedders={'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0'}
    response=requests.get(url,headers = mhedders)
    if response.status_code == 200:
        print('success to open url')
        return response.text
    else:
        print('fale to open url')
        return None
def get_lat_lon(addr):
#    mhedders={'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0'}
    url='http://api.map.baidu.com/geocoder?address=四川省成都市'+addr
    response=requests.get(url,headers = mhedders)
    if response.status_code == 200:
        print('success to get lat lng_lat')
        html=response.text
       # print(html)
        soup = BeautifulSoup(html,'lxml')
        lat=soup.find('lat').string.strip()
        long=soup.find('lng').string.strip()
        return long,lat
    else:
        print('fale  to get lng_lat')
        return None
def geocodeB(address):
    base = url = "http://api.map.baidu.com/geocoder?address=" + address + "&output=json&key=ZynhLGf0disO4CDGe57eghnOZO2bOSO9"
    response = requests.get(base)
    answer = response.json()
    print (answer)
    return answer['result']['location']['lng'],answer['result']['location']['lat']
def deal_one_page(html):
    soup = BeautifulSoup(html,'lxml')
    items = soup.findAll('div',{'class':'pan-item clearfix'})
    for item in items:
        house_tag=item.find('p',{'class':'p_hx'})
        house_msg = []
        for  item_tag in house_tag.find_all('em'):
            house_msg.append(item_tag.string.replace("\n", "").replace("\r", "").strip())
        addr=house_tag.find_next_sibling().string.strip()
        house_name=addr.split('[')[0]
        addr_xx='四川省成都市'+addr
       # lng,lat=get_lat_lon(addr)
        lng,lat=geocodeB(addr_xx)
        lats.append(float(lat))
        lons.append(float(lng))
        labels.append(house_name)
        agency_tag=item.find('p',{'class':'p_gx'})
        agency_msg = []
        for  item_tag in agency_tag.find_all('em'):
            agency_msg.append(item_tag.string.replace("\n", "").replace("\r", "").strip())

        yield {
            'source':item.find('span',{'class':'zj'}).string,
            'intro':item.h2.a.string,
            'house_name':house_name,
            'size':house_msg[0],
            'room':house_msg[1],
            'floor':house_msg[2],
            'build':house_msg[3],
#            'addr':house_tag.find_next_sibling().string.strip(),
            'addr':addr,
            'total_price':item.find('strong',{'class':'total-price'}).i.string ,
            'price':item.find('strong',{'class':'h-price'}).string,
            'agency_name':agency_msg[0],
            'agency_person':agency_msg[1],
            'date':agency_msg[3],
            'check':item.find('div',{'class':'yhy'}).string,
            'check_num':item.find('div',{'class':'ynum'}).a.string,
            'bsale':item.find('em',{'class':'yellow'}).string,
            'bpledge':item.find('em',{'class':'right-5 green'}).string,
            'lng':lng,
            'lat':lat
        }
def write_to_file(content):
    with open('./lianjia.csv','a',encoding='utf-8')as f:
       # print(type(json.dumps(content)))
        fieldnames =['source','intro','house_name','size','room','floor','build','addr','total_price','price','agency_name','agency_person','date','check','check_num','bsale','bpledge','lng','lat']
        writer=csv.DictWriter(f, fieldnames=fieldnames)
 #       f.write(json.dumps(content,ensure_ascii=False)+'\n')
        writer.writerow(content)
def parse_one_page(num): 
    url='http://esf.cdfgj.gov.cn/search?page='+str(num)+'&qy=510109'
    print(url)
    html=open_one_page(url)
    for item in deal_one_page(html):
        write_to_file(item)
if __name__=='__main__':
    for i in range(1,100):
        parse_one_page(i)
        time.sleep(2)        
   # url='http://esf.cdfgj.gov.cn/search?page=1&qy=510109'
   # html=open_one_page(url)
   # i=0
   # for item in deal_one_page(html):
     #   i=i+1
    #    print(i)
   #     write_to_file(item)
  #  print(lats)
 #   print(lons)
 #   print(labels)
#    draw_data_map()
