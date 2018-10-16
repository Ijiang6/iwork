#codeing=utf-8
from socket import *
global file_name
def tcp_lient(HOST,PORT):
    ADDR=(HOST,PORT)
    tctimeClient= socket(AF_INET,SOCK_STREAM)
    tctimeClient.connect(ADDR)
    while True:
        print("link server success")
        tctimeClient.send( tcp_send('txt','test','the msg from python client\n'))
        byte=tctimeClient.recv(BUFFSIZE)
        tcp_recv(byte)
        break
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
    if(str(byte[0]) =='$'):
        btype=byte[1:5]
        loc=5
        itype=int.from_bytes(btype,byteorder = 'little')
        stype=byte[loc:loc+itype]
        loc+=itype
        bname=byte[loc:loc+4]
        iname=int.from_bytes(bname,byteorder='little')
        loc+=4
        sname=byte[loc:loc+iname]
        sfile=(sname+stype).decode()
        if(sfile != file_name):
            file_name=sfile
        loc+=iname
        loc+=4
        sdata=byte[loc:]
        print("recv data:"+str(sdata)+"size:"+str(len(sdata)))
        file_write(byte)
    else:
        print("head error")
def file_write(byte):
     with open(file_name,'a') as file:
        file.write(byte.decode())
        file.flush()


if __name__=='__main__':
    HOST='127.0.0.1'
    PORT=8989
    BUFFSIZE=1024
    tcp_lient(HOST,PORT)
