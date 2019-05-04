#include<iostream>
using namespace std;
/*
 *LeetCode
 * remove duplicates from sorted array
 * retun length
 *do not allocate extra space
 *
 * */
class Solution
{

public :
    int removeDulicates(int a[],int n)
    {
	if(n == 0)
	{
	    return 0;
	}
	int  iPos = 0;
	for(int iIndex = 1; iIndex<n;iIndex++)
	{
	    if( a[iIndex] != a[iPos])
	    {
		a[++iPos]=a[iIndex];
	    }
	}
	return iPos+1;
    }

};
int main(char *agrc[],int argc)
{
    Solution text;
    int a[]={1,1,2};
    cout<<text.removeDulicates(a,3)<<endl;
    return 0;

}
