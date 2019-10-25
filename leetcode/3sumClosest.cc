#include<iostream>
#include<vector>
using namespace std;
class Solution
{
 public:
     static void out_vector(const vector<int> vec)
     {
       for(int index =0; index< vec.size() ;++index)
       {
         cout<<index<<":"<<vec[index]<<endl;
       }
     
     }
    static  void out_array(int a[] ,int n)
    {
	for(int index =0; index< n;++index)
	{
	    cout<<a[index]<<endl;
	}
    }
    static void sort_array(int a[] ,int n)
    {
	for(int i=0;i<n; ++i)
	{
	   for(int j= i+1;j<n;++j)
	   {
	       if(a[i]>a[j])
	       {
		  a[i]=a[i]^a[j];
		  a[j]=a[i]^a[j];
	          a[i]=a[i]^a[j];
	       }
	   }
	}
    
    }
    static  int fun_1(int array[] ,int n ,int target)
     {
	 vector<int>vec;
	  sort_array(array,n);
	  int pre_sum=target;
	  int gap=9999;
	for(int a=0; a< n;++a)
	{
		int b=a+1;
		int c =n-1;
		while(b<c)
		{
		 int temp_sum = array[a]+array[b]+array[c];
              	 int temp = abs(temp_sum - target);
		  if(temp == 0)
		  {
		      vec.clear();
		      vec.push_back(a);
		      vec.push_back(b);
		      vec.push_back(c);
		      cout<<"index in sorted arrary:"<<endl;
		      out_vector(vec);
		      return temp_sum;
		  }
		  if(gap == 9999 || temp < gap)
		  {
		      vec.clear();
		      vec.push_back(a);
		      vec.push_back(b);
		      vec.push_back(c);
		      pre_sum =temp_sum;
		  }
		   temp_sum >target ? --c:++b;
		}
	}
	   cout<<"index in sorted arrary:"<<endl;
	   out_vector(vec);
	   return pre_sum;
     }
};
int main(char *argv[] ,int argc)
{
    int a[4] = {-1,2,1,-4};
    cout<<"target 2 closest sum:"<<Solution::fun_1(a,4,2)<<endl;

    cout<<"target 1 closest sum:"<<Solution::fun_1(a,4,1)<<endl;
    cout<<"target 3 closest sum:"<<Solution::fun_1(a,4,3)<<endl;
    return 0;
}
