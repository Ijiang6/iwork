/*
 *
 *Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true
 *
 *
 *
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
#include<stack>
using namespace std;
class Solution
{
    public :
    static bool fun_1(const string &exp)
    {
	int maxL =0;
	bool bValid = true;
	stack<char> chStack;
	auto it = exp.begin();
	while( it != exp.end())
	{
	    if(*it == '(' || *it =='[' || *it =='{')
	    {
	      chStack.push(*it);
	    }
	    else
	    {
		char chB ='0';
	    
		if(*it == ')')
	    {
		chB ='(';
	    }
	    else if(*it == ']')
	    {
	    chB = '[';
	    }
	    else if(*it == '}')
	    {
		chB ='{';
	    }
	    if(chStack.top() == chB)
	    {
	      ++maxL;
	      chStack.pop();
	    }
	    else
	    {
	     bValid = false;
	     break;
	    }
	    }
	++it;
	}
     if(chStack.size()>0)
     {
       bValid = false;
     }
cout<<"maxL"<<maxL<<endl;
return bValid;
    }


};

int main( char *argv[] ,int argc)
{
    string exp_1 ="{{{[({})]}}}";
    string res = "true";
    if(!Solution::fun_1(exp_1))
    {
	res = "false";
    }
    cout <<exp_1 << ":"<< res<<endl;
return 0;
}
