#-*- coding:utf-8 -*-
from PIL import Image
import argparse
Ascchar = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ")
def getchar(r,g,b,alpha=256):
    if alpha==0:
        return ' '
    length=len(Ascchar)
    gray=int(0.2126*r+0.7152*g+0.0722*b)
    unit=(256.0+1)/length
    return Ascchar[int(gray/unit)]

if __name__=='__main__':
    img=Image.open('./img.jpg')
    img=img.resize((80,80),Image.NEAREST)
    txt=""
    for i in range(80):
        for j in range(80):
            txt+=getchar(*img.getpixel((j,i)))
        txt+='\n'
    print(txt)
    with open("img.txt",'w') as f:
        f.write(txt)

