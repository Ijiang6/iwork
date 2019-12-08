/*
 *Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return”100”.
 *
 */

#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

class Solution
{
    public:
	static string fun_1( string a, string b)
	{
	    string res;
	    const int size_n = a.size() > b.size() ? a.size() : b.size();
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
	    int carry =0;

	    for(int index =0; index < size_n ;++index)
	    {
		int cha = index < a.size() ? a[index]-'0' :0;
		int chb = index <b.size() ? b[index] - '0' :0;
		int val = (cha+chb+carry)%2;
		 carry = (cha+chb+carry)/2;
		res.insert(res.begin(),val+'0');
	    }
	    if( carry >0)
	    {
	      res.insert(res.begin(),'1');
	    }
	return res;
	}
};
int main(char *argv[] ,int argc)
{
    string a = "11";
    string b ="11";
   cout<< Solution::fun_1(a,b)<<endl;


return 0;
}
