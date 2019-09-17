#include "removeduplicatessoredarray.h"
#include<iostream>
using namespace std;
/*
 * Remove Duplicates from Sorted Array II

Follow up for ”Remove Duplicates”: What if duplicates are allowed at **most twice**?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
 *
 */
#define LEN(x) sizeof(x) / sizeof(x[0])
int RemoveDuplicatesSoredArray::fun1(int a[] ,int n)
{
    if( n < 3  )
    {
        return n;
    }
    int iIndex = 2 ;
    for( int iNum = 2 ; iNum < n ; iNum ++ )
    {
        if ( a[iNum] != a[iIndex-2] )
        {
            a[iIndex++] = a[iNum];
        }
    }
    return iIndex;
}
int RemoveDuplicatesSoredArray::fun2(int a[] ,int n)
{
    if ( n < 3 )
    {
        return n;
    }
    int iLength =0;
    for ( int iIndex =0 ; iIndex < n ; iIndex++ )
    {
        if( iIndex >0 && iIndex < n -1  && a[iIndex -1] == a[iIndex] && a[iIndex] == a[iIndex+1] )
        {
            // index:0 1 2 3 4 5
            //value :1 1 1 2 2 3
            continue;//a[1]
        }
        /*
         *a[0] = a[0] ->iLength = 1 -> 1 1 1 2 2 3
         *a[1] = a[2] ->iLength = 2 -> 1 1 1 2 2 3
         *a[2] = a[3] ->iLength = 3 -> 1 1 2 2 2 3
         *a[3] = a[4] ->iLength = 4 -> 1 1 2 2 2 3
         *a[4] = a[5] ->iLength = 5 -> 1 1 2 2 3 3
         */
        a[iLength++] = a[iIndex];

    }
    return  iLength;

}
RemoveDuplicatesSoredArray::RemoveDuplicatesSoredArray()
{

    int array[] ={ 1,1,1,2,2,3 };
    cout <<"--->"<< fun2(array,LEN(array))<<endl;

}
