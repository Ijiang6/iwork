# -*- coding: UTF-8 -*-
from socket import *
from filetool import *
file_name=''
balldata=bytes()
def tcp_lient(HOST,PORT):
    ADDR=(HOST,PORT)
    tctimeClient= socket(AF_INET,SOCK_STREAM)
    tctimeClient.connect(ADDR)
    print("link server success")
    while True:
        tctimeClient.send( tcp_send('txt','test','the msg from python client\n'))
        byte=tctimeClient.recv(1024)
        if(len(byte) == 0):
            print('no data')
            break 
        tcp_recv(byte)
    tctimeClient.close()

def tcp_send(str_type,str_name,str_data):
    btype=str_type.encode()
    byte_itype=(len(str_type)).to_bytes(4,byteorder='little')

    bname=str_name.encode()
    byte_iname=(len(str_name)).to_bytes(4,byteorder='little')
    bdata=str_data.encode()
    data_size=len(str_data)
    byte_isize=(data_size).to_bytes(4,byteorder='little')
    sdata=b'$'+(byte_itype)+btype+(byte_iname)+bname+(byte_isize)+bdata
    print('send  data:'+str(sdata)+'size:'+str(data_size))
    return sdata
def tcp_recv(byte):
    global file_name
    global balldata
    print(len(byte))
    print(byte[0])
    chbhead=chr(byte[0])
    if(chbhead =='$'):
        btype=byte[1:5]
        loc=5
        itype=int.from_bytes(btype,byteorder = 'little')
        stype=byte[loc:loc+itype]
        loc+=itype
        loc+=4
        sname=byte[loc:loc+iname]
        sfile=(sname.decode())+'.'+stype.decode()
        print(sfile)
        print(file_name)
        if(sfile != file_name):
            file_name=sfile
        loc+=iname
        bdatalen=byte[loc:loc+4]
        idata=int.from_bytes(bdatalen,byteorder='little')
        print((idata))
        loc+=4
        bdata=byte[loc:]
        if(len(bdata) >0):
            balldata+=(bdata)
            print(bdata)
        else:
            print("ready to write file")
            file_write(balldata.decode())
            balldata.clear()
    else:
        print("head error")
def file_write(byte):
     with open(file_name,'a') as file:
        file.write(byte)
        file.flush()

def hex_to_str(b):
    s = ''
    for i in b:
        s += '{0:0>2}'.format(str(hex(i))[2:])
    print(s)
    return(s)

if __name__=='__main__':
    HOST='127.0.0.1'
    PORT=8989
    BUFFSIZE=1024
    tcp_lient(HOST,PORT)
