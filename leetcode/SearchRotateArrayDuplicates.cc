/*Search in Rotated Sorted Array II
Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array

————————————————
Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.
*/
#include<iostream>
using namespace std;
class SeachRotate

{
    public :
	static int  fun_1(int a[] ,int n ,int target)
	{
	    int left  = 0;
	    int right = n-1;
	    while( left != right)
	    {
		int mid = (left + right )/2;
		if(a[mid]== target)
		{
		    return mid;
		}

		if(a[left] < a[mid])
		{
		    if(a[left]<= target && a[mid] > target)
		    {
			right = mid;
		    }
		    else
		    {
			left = mid;
		    }
		}
		else if(a[left]>a[mid])
		{
		    if(a[right] >= target && a[mid]< target)
		    {
			left = mid;
		    }
		    else
		    {
			right = mid;
		    }
		}
		else
		{
		    //skip duplicate item 
		    left++;
		}

	    }
	    return -1;
	}


};
int main(char *argv[] ,int argc)
{
	//   0,1,2,3,4,5,6
int a[7] = { 0,1,2,4,5,6,7};
int b[7] = { 4,5,6,7,0,1,2};
int c[7] = { 1,1,6,1,1,1,1};

 cout <<"Search:1"<<"pos"<<SeachRotate::fun_1(a,7,1)<<endl;
 cout <<"Search:1"<<"pos"<<SeachRotate::fun_1(c,7,6)<<endl;
 return 0;
}
