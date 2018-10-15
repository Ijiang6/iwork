#codeing=utf-8
from socket import *
HOST='127.0.0.1'
PORT=8989
BUFFSIZE=1024
ADDR=(HOST,PORT)
tctimeClient= socket(AF_INET,SOCK_STREAM)
tctimeClient.connect(ADDR)
while True:
    print("link server success")
    str_type='txt'.encode()
    byte_itype=(3).to_bytes(4,byteorder='little')
    str_name='test'.encode()
    byte_iname=(4).to_bytes(4,byteorder='little')
    file_data='this is a test\n'.encode()
    data_size=len(file_data)
    byte_isize=(data_size).to_bytes(4,byteorder='little')
    sdata=b'$'+(byte_itype)+str_type+(byte_iname)+str_name+(byte_isize)+file_data
#     data = input(">")
 #    if not data:
 #        break
    tctimeClient.send(sdata)
    print('seend data:'+str(sdata))
    print('data_size:'+str(data_size))
    print( tctimeClient.recv(BUFFSIZE).decode())
    break
    # print(data)
tctimeClient.close()
