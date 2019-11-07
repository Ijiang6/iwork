/*
 *给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true

示例 2:

输入: s = "rat", t = "car"
输出: false

说明:
你可以假设字符串只包含小写字母。

 *
 *
 *
 *
 *
 *
 *
 */
#include<iostream>
#include<string>
using namespace std;

class Solution
{
    public:
	static bool  fun_1(const string &s,const string  &t)
	{
	    int abc[26]={0};
	    if(s.size() != t.size())
	    {
		return false;
	    }
      auto it = s.begin();

      while( it != s.end())
      {
	  ++abc[*it-97];
	    ++it;
      }
      it = t.begin();

      while(it != t.end())
      {
       --abc[*it-97];
   	++it;
      }
      bool bValid = true;
     for(int index =0;index < 26;++index)
     {
	 if(abc[index] != 0)
	 {
           bValid = false;
           break;
	 }
     
     }
     return bValid;
    }


};

int main( char *argv[] ,int argc)
{
 string s="anagram";
 string t ="nagaram";
 string res="true";
 if(!Solution::fun_1(s,t))
 {
   res="false";
 }
 cout<<"res:"<<res<<endl;

return 0;
}
