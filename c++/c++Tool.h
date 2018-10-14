#pragma once
#include<string.h>
using namespace std;
class cplusplusTool
{
public:
  static int byte_to_int(const char * bytes)
  {
      int iNum = bytes[0] & 0xFF;
      iNum |= ((bytes[1] << 8) & 0xFF00);
      iNum |= ((bytes[2] << 16) & 0xFF0000);
      iNum |= ((bytes[3] << 24) & 0xFF000000);
      return iNum;
  }


};
