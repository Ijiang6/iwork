import requests
import os
import time
import json
from hashlib import md5
from  urllib.parse import urlencode
from requests.exceptions import RequestException
def requestPage(offset):
    paras={
        'offset':offset,
        'format':'json',
        'keyword': '街拍',
        'autoload':'true',
        'count':'20',
        'cur_tab':'1',
        'from':'search_tab',
        'pd': 'synthesis',
        }
    url='https://www.toutiao.com/search_content/?'+urlencode(paras)
    try:
        resPage=requests.get(url)
        if resPage.status_code == 200:
            return resPage.json()
    except RequestException:
        print('request'+url+"error")
        return None
def parsePage(jsonData):
    if jsonData and 'data' in jsonData.keys():
        for item in jsonData.get('data'):
            strtitle= item.get('media_name')
            images= item.get('image_list')
            if not images:
                print("parsePage return NULL")
                return None
            for image in images:
                yield {     
                     'image':image.get('url'),
                    'title':strtitle,
                    }
def saveImage(image):
    strPath=image.get('title')
    if not os.path.exists(strPath):
        os.mkdir(strPath)
    try:
        image_url= image.get('image')
        url='http:'+image_url
        res=requests.get(url)
        if res.status_code == 200:
            imag_path = '{0}/{1}.{2}'.format(strPath,md5(res.content).hexdigest(),'jpg')
            if not os.path.exists(imag_path):
                with open(imag_path,'wb') as file:
                    file.write(res.content)
            else:
                print(imag_path+'has Downloade')
        else:
            print("request image url error")
    except:
        print("Faild to saveImage")

if __name__ == '__main__':
    pageNum=([index*20 for index in range(1,20)])
    for page in pageNum:
        print(page)
        htmldata=requestPage(page)
        images=parsePage(htmldata)
        if not images:
            print("none parsePage return")
            continue
        for image  in images:
            print(image)
            saveImage(image)
