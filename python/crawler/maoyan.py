import requests
import time
import re
import json
import csv
def get_one_page(url):
    hedders={'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:61.0) Gecko/20100101 Firefox/61.0'}
    response = requests.get(url,headers=hedders)
    if response.status_code == 200:
        return response.text
    return None
def parse_one_page(html):
    pattern=re.compile(
            '<dd>.*?board-index-.*?>(.*?)</i>.*?data-src="(.*?)".*?name.*?a.*?>(.*?)</a>.*?star.*?>(.*?)</p>.*?releasetime.*?>(.*?)</p>.*?integer.*?>(.*?)</i>.*?fraction.*?>(.*?)</i>.*?</dd>',re.S)
    items =re.findall(pattern,html)
    for item in items:
        yield{
                'index':item[0],
                'image':item[1],
                'title':item[2].strip(),
                'actor':item[3].strip()[3:] if len(item[3])>3 else '',
                'time':item[4].strip()[5:] if len(item[4])>5 else '',
                'score':item[5].strip()+item[6].strip()
            }
def write_to_file(content):
    with open('./maoyan.csv','a',encoding='utf-8')as f:
        print(type(json.dumps(content)))
        fieldnames =['index','image','title','actor','time','score']
        writer=csv.DictWriter(f, fieldnames=fieldnames)
 #       f.write(json.dumps(content,ensure_ascii=False)+'\n')
        writer.writerow(content)
def main(offset):
    url ='http://maoyan.com/board/4?offset='+str(offset)
    html = get_one_page(url)
    for item in parse_one_page(html):
        write_to_file(item)
if __name__=='__main__':
    for i in range(10):
        main(offset=i*10)
        time.sleep(1)


