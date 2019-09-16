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


}
RemoveDuplicatesSoredArray::RemoveDuplicatesSoredArray()
{

    int array[] ={ 1,1,1,2,2,3 };
    cout <<"--->"<< fun1(array,LEN(array))<<endl<<array;

}
