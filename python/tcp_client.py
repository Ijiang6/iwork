# -*- coding: UTF-8 -*-
from socket import *
import select
from filetool import *
file_name=''
balldata=bytes()
read=[]
write=[]
filelines=[]
filetool=CFileTool()
class CTcpClient():
    def tcp_client(self,HOST,PORT):
        ADDR=(HOST,PORT)
        tcpClient= socket(AF_INET,SOCK_STREAM)
        tcpClient.connect(ADDR)
        read.append(tcpClient)
        write.append(tcpClient)
        print("link server success")
        while True:
            self.tcp_data(tcpClient)


    def tcp_data(self,tcpClient):
        r_list,w_list,e_list=select.select(read,write,read,1)
        for sk in w_list:
            try:
                bdata=self.tcp_send()
                tcpClient.send(bdata)
            except Exception as e:
                print("wlist")
                print(e)
                write.remove(sk)
        for sk in r_list:
            try:
                byte=tcpClient.recv(1024)
                if(len(byte) == 0):
                    print('no data')
                else:
                    self.tcp_recv(byte)
            except Exception as e:
                print(e)
                read.remove(sk)
        for sk in e_list:
            sk.close()
            print('close socket')


    def tcp_send(self):
        #global file_name
        #file_name='demo.txt'
        print(file_name)
        filemsg=file_name.split('.')
        str_type=filemsg[1]
        str_name=filemsg[0]
        if filelines is not None:
            str_data=filelines.pop(0)
        else:
            return
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

    def tcp_recv(self,byte):
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
            bname=byte[loc:loc+4]
            iname=int.from_bytes(bname,byteorder='little')
            loc+=4
            sname=byte[loc:loc+iname]
            sfile=(sname.decode())+'.'+stype.decode()
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
                self.file_write(balldata.decode())
                balldata.clear()
        else:
            print("head error")

    def file_write(self,byte):
        with open(file_name,'a') as file:
            file.write(byte)
            file.flush()

    def file_read(self,strpath):
        global filelines
        filetool.setFile(strpath,'r')    
        filelines=filetool.fileToLines() 
    
    def set_file_name(self,strfile):
        global file_name
        file_name=strfile
    def init(self):
        HOST='127.0.0.1'
        PORT=8989
        BUFFSIZE=1024
   # file_read('./demo.txt')
        self.tcp_client(HOST,PORT)
