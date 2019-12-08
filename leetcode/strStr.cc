/*Implement strStr()
.Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/
#include <iostream>
#include <string>
using  namespace  std;
class Solution 
{
    public :
    static int  fun_1(const string  haystack,const string  needle)
    {
        if(needle.size() == 0)
        {
            return 0;
        }
        else if(haystack.size() ==0 || needle.size() > haystack.size())
        {
            return -1;
        }
        int index = -1;
        int  i =0;
            for (size_t j = 0; j < haystack.size(); j++)
            {
                if(haystack[j] == needle[i])
                {
                    index <0 ? index = j  :index ;
                    ++i;
                }
                else if( i < needle.size())
                {
                    i=0;
                    index = -1;
                    continue;
                }
                else
                {
                    if(i != needle.size())
                        {
                            index = -1;
                        }
                    break;
                }
            }
            
            return  index;
    }
    static   int  fun_2(const string haystack ,const string needle)
    {
        if(needle.size() == 0)  return 0;

        if(haystack.size() < needle.size()) return -1;

        for (size_t i = 0; i < haystack.size() -  needle.size() +1; ++i)
        { 
            string  s =haystack.substr(i,needle.size());
            if(haystack.substr(i,needle.size()) == needle )
            {
                return i;
            }
        }
         return -1;
    }

};

 int main(int argc,  char** argv) 
{
  string str1= "hello word";
  string str2="ord";
  cout<< "strStr2:"<<Solution::fun_2(str1,str2)<<endl;
  cout<< "strStr:"<<Solution::fun_1(str1,str2)<<endl;

     str1= "hello";
   str2="ll";
  cout<< "strStr:"<<Solution::fun_1(str1,str2)<<endl;
    cout<< "strStr2:"<<Solution::fun_2(str1,str2)<<endl;
       str1= "hello";
   str2="hello";
  cout<< "strStr:"<<Solution::fun_1(str1,str2)<<endl;
    cout<< "strStr2:"<<Solution::fun_2(str1,str2)<<endl;
    return 0;
}

