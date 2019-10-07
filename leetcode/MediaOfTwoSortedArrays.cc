/*Median of Two Sorted Arrays
 *
 * there are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sortedarrays.
 * the overall run time complexity should be O(log(m + n))
 *
 *
 * */

#include<iostream>
using namespace std;

class MediaOfAB
{
    public:
	// time complexity  O(K) k-> m+n : O(m+n)
	static int fun_1(int a[],int m,int b[],int n)
	{
	    int pA =0;
	    int pB = 0;
	    int median = (m+n)>>1;//no overflow
	    int k=0;
	    int value = -1;
	    while( k <= median )
	    {
		if(a[pA] < b[pB] )
		{
		    value = a[pA];
		 if(pA < m)
		 {
		     pA++;
		 }
		    k++;
		}
		else if( a[pA]> b[pB]  ) 
		{
		    value = b[pB];
		     if(pB<n)
		     {
			 pB++;
		     }
		    
		    k++;
		}
		else if(k< m && k < n )
		{
		    pB++;
		    pA++;
		
		    value = a[pA];
		    k++;
		}
	    }

	    return value; 
	}

};
int main(char*argv[] , int argc)
{
    // 0,1,2,3,4,5,7,9
 int a[3] = {0,2,4};
 int b[5] = {1,3,5,7,9};
cout<<"media:"<<MediaOfAB::fun_1(a,3,b,4)<<endl;
return 0;
}
