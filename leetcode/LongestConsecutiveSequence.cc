/*
 * Longest Consecutive Sequence
 *
    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

    For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
 *
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
 public :
     static int fun_1(vector<int> const & vNums )
     {
	unordered_map<int,bool> mNums;
	 for( auto i :vNums)
	 {
	  mNums[i] =false;
	 }
      int iLongest =0;
      for(auto k : vNums)
      {
	  if( mNums[k] )
	  {
	      continue;
	  }
	  int length =1;

	  for(int j = k+1 ; mNums.find(j) != mNums.end() ;j++)
	  {
	   mNums[j] = true;
	   ++length;
	  }

      for(int j = k-1 ; mNums.find(j) != mNums.end() ;j--)
      {
	   mNums[j] = true;
	   ++length;
	  } 
      
       iLongest=max(iLongest,length);
      }
	return iLongest;
     }
// std::vector hava no indexof api
/*
 static int fun_2(vector<int> const & vNums)
 {
`   int  iLongest =1;
 for(auto k : vNums)
 {
     int iLength =0;
  for(int key =k+1 ; vNums.indexOf(K);++K)
  {
   iLength++;
  }
  for(int key =k-1 ; vNums.indexOf(K);--K)
  {
   iLength++;
  }
  iLongest= max(iLength,iLongest);
 }
 return iLongest;
 }*/
};
int main(char *argv[] ,int argc)
{
    vector<int> vNums = {100,4,200,1,3,2};
    cout<<"Longest:"<<Solution::fun_1(vNums)<<endl;

return 0;
}
