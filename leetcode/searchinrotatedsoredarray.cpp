#include "searchinrotatedsoredarray.h"
#include<iostream>
using namespace  std;
//0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
SearchInRotatedSoredArray::SearchInRotatedSoredArray()
{           //  0 1 2 3 4 5 6
    int a[7] = {0,1,2,4,5,6,7};
    int b[7] = {4,5,6,7,0,1,2};
    int c[7] = {6,7,0,1,2,4,5};
    int d[7] = {7,0,1,2,4,5,6};
    printf("afsad");
    cout << "src key =1 pos="<<fun_1(a,7,1);
    cout << "Ratate 3 key =1 pos="<<fun_1(b,7,1);
    cout << "Ratate 2 key =1 pos="<<fun_1(c,7,1);
    cout << "Ratate 1 key =1 pos="<<fun_1(d,7,1);

}
int SearchInRotatedSoredArray::fun_1(int a[] ,int n ,int target)
{
    int left =0;
    int right = n-1 ;
    while(left != right)
    {
        int mid = (left+right)/2;

        if(a[mid] == target)
        {
            return mid;
        }

//        int a[7] = {0,1,2,4,5,6,7};
//        int b[7] = {4,5,6,7,0,1,2};
        if( a[left] < a[mid] )
        {
           // left ~ mid :ascending order
          if( a[left] <= target && a[mid] > target )
          {
              //a[left] <target <a[mid]
              right = mid;
          }
          else {
              left = mid;
          }
        }
        else
        {
            if(a[right] >= target && a[mid] < target)
            {
                //a[mid] <target <=a[right]
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
    }
    return  -1;
}
