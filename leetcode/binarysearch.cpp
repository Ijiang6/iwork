#include "binarysearch.h"
/*
 *
 * int  iMid=(iLeft+iRight)*0.5;//maybe overflow
if( (iLeft > (int/2)) &&  (iRight>(int/2)))
{
  (iLeft+iRight)>int// overflow
}
*/
bool BinarySearch::fun_1(const vector<int> & vSrc,const int iKey,int &iIndex)
{

    int iLeft =0,iRight=vSrc.size()-1;
    int index=-1;
    while (iLeft<iRight) {
        if(vSrc[iLeft] == iKey)
        {
            index=iLeft;
            break;
        }
        else if(vSrc[iRight] == iKey)
        {
            index = iRight;
            break;
        }
        else
        {
            int  iMid=(iLeft+iRight)*0.5;//maybe overflow
            if(vSrc[iMid] == iKey)
            {
                index =iMid;
                break;
            }
            else if (vSrc[iMid] > iKey)
            {
                iRight=iMid-1;
            }
             else if (vSrc[iMid] < iKey)
              {
                   iLeft=iMid+1;
              }

        }

    }
    iIndex=index;
    return iIndex<0 ? false :true;
}
bool BinarySearch::fun_2(const vector<int> & vSrc,const int iKey,int &iIndex)
{
    int iLeft = 0;
            int iRight = vSrc.size() - 1;
            int mid;
            while (iLeft <= iRight) {
                mid = (iLeft + iRight) / 2;
                if (vSrc[mid] > iKey) {
                    iRight = mid - 1;
                } else if (vSrc[mid] < iKey) {
                    iLeft = mid + 1;
                } else {
                    iIndex= mid;
                    break;
                }
            }
          return iIndex<0 ? false :true;
}

bool BinarySearch::fun_3(const vector<int> & vSrc,const int iKey,int &iIndex)
{
    int iLeft = 0;
    int iRight = vSrc.size() - 1;
    int mid;
     while (iLeft <= iRight) {
         mid = iLeft+(iRight-iLeft) / 2;//no overflow
         if (vSrc[mid] > iKey)
         {
            iRight = mid - 1;
         }
         else if (vSrc[mid] < iKey)
         {
              iLeft = mid + 1;
          } else
         {
             iIndex= mid;
             break;
          }
        }
     return iIndex<0 ? false :true;
}
/* <<，有符号左移位，将运算数的二进制整体左移指定位数，低位用0补齐。
*  >>，有符号右移位，将运算数的二进制整体右移指定位数，整数高位用0补齐，负数高位用1补齐（保持负数符号不变）
*  >>>，无符号右移位，不管正数还是负数，高位都用0补齐（忽略符号位）
       正数的>>>无符号右移位和>>有符号右移位计算结果相同
*/
bool BinarySearch::fun_4(const vector<int> & vSrc,const int iKey,int &iIndex)
{
    int iLeft = 0;
    int iRight = vSrc.size() - 1;
    int mid;
     while (iLeft <= iRight) {
         mid = iLeft+((iRight-iLeft)>>1);//no overflow
         if (vSrc[mid] > iKey)
         {
            iRight = mid - 1;
         }
         else if (vSrc[mid] < iKey)
         {
              iLeft = mid + 1;
          } else
         {
             iIndex= mid;
             break;
          }
        }
     return iIndex<0 ? false :true;
}
bool BinarySearch::fun_5(const vector<int> & vSrc,const int iKey,int &iIndex)
{
    iIndex=fun_recursive(vSrc,iKey,0,vSrc.size()-1);
     return iIndex<0 ? false :true;
}
int BinarySearch::fun_recursive(const vector<int> & vSrc,const int iKey,int iLeft,int iRight)
{
    if(iLeft>iRight)
    {
        return -1;
    }
    int iMid=iLeft+(iRight-iLeft)*0.5;
    if(vSrc[iMid] == iKey)
    {
        return  iMid;
    }
    else if(vSrc[iMid] < iKey)
    {
        fun_recursive(vSrc,iKey,iMid+1,iRight);
    }
    else
    {
        fun_recursive(vSrc,iKey,iLeft,iMid-1);
    }

}
