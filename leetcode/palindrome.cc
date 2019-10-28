/*
 * Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring

cases.

For example,

”A man, a plan, a canal: Panama” is a palindrome.

”race a car” is not a palindrome.

Note: Have you consider that the string might be empty? this a good question to ask during an

interview.

For the purpose of this problem, we define empty string as valid palindrome

*/

#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

class Solution
{
  public :
      static bool fun_1(string str)
      {
	 if(str.empty())
	 {
	  return true;
	 }
       // Uppter -> lower
       transform(str.begin(),str.end(),str.begin(),::tolower);
       auto left= str.begin();
       auto  right = str.end();
       right--;
       while(left <right )
       {
	   if(!isalnum(*left)) ++left;// isalnum : 0~9 a~z
	   else if(!isalnum(*right)) --right;
          else if(*left != *right) return false;
	  else
	  {
	   ++left;
	   --right;
	  }
       }
       return true;
      }

};


int main(char*argv[],int argc)
{
  string str ="A man, a plan, a canal: Panama";
  string res=Solution::fun_1(str) ?"true":"false";
  cout<<str<<"->"<<res<<endl;
return 0;
}


