#pragma once
#include<string.h>
using namespace std;
class cplusplusTool
{
public:
  static int byte_to_int(const char * bytes)
  {
      //little byteorder
      int iNum = bytes[0] & 0xFF;
      iNum |= ((bytes[1] << 8) & 0xFF00);
      iNum |= ((bytes[2] << 16) & 0xFF0000);
      iNum |= ((bytes[3] << 24) & 0xFF000000);
      return iNum;
  }
  static char * int_to_byte(int iNum)
  {
      //little byteorder
    int isize=iNum;
    char *byte= new char[4];
    bzero(byte,4);
    byte[3]=(char)((isize>>24)&0xFF);    
    byte[2]=(char)((isize>>16)&0xFF);    
    byte[1]=(char)((isize>>8)&0xFF);    
    byte[0]=(char)((isize)&0xFF);    
    return byte;   
  }


};
