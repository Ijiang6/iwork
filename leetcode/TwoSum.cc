/*
 *
 * Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

 The  function twoSum should return indices of the two numbers such that they add up to the target,

where index1 must be less than index2. Please note that your returned answers (both index1 and index2)

are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9

Output: index1=1, index2=2
 *
 *
 *
 *
 */
#include<iostream>
#include<unordered_map>
typedef struct 
{
    int index1;
    int index2;

}Pair;
using namespace std;

class Solution
{
    public:
    static Pair fun_1( int a[] ,int  n,int target)
    { 
	Pair pair;

	pair.index1 =0;
	pair.index2 = 0;
	for( int i = 0; i<n ;++i)
	{
	    for(int j= i+1 ;j<n ; ++j)
	    {
		if(a[i] + a[j] == target)
		{
		  pair.index1 = i+1;
		  pair.index2 = j+1;
		  return pair;
		}	    
	    }
	}
	return pair;
    }
    static Pair fun_2(int a[] , int n , int target)
    {
      Pair pair;
      pair.index1 = 0;
      pair.index2 = 0;
    unordered_map<int ,int > mNums;

    for( int i = 0; i < n ; ++i)
    {
      mNums[a[i]] =i+1;
    }
    for (int index = 0; index <n ;++ index)
     {
	 int temp = target - a[index];

	 if(mNums.find(temp) != mNums.end())
	 {
	    pair.index1 = index+1;
	    pair.index2 = mNums[temp];
	    return pair;
	 }
     }
     return pair;
    }

};
int main(char *argv[] ,int argc)
{	    //  1,2,3,4
    int a[4] = {2,7,9,11};
    Pair pair = Solution::fun_1(a,4,13);
    cout<< "index1: "<<pair.index1<< "index2:"<< pair.index2<<endl;
    pair = Solution::fun_2(a,4,13);
    cout<< "index1: "<<pair.index1<< "index2:"<< pair.index2<<endl;

return  0;
}
