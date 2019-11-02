/*
 * Plus One
 *
    Given a number represented as an array of digits, plus one to the number.
*
*
*
*
*
*
*/
#include<iostream>
#include<vector>
using namespace std;
 class Solution
{
    public :
	static void   fun_1(vector<int> & digits)
	{
	    auto it = digits.end();
	     --it;
	     int temp=1;
	     while( it >= digits.begin())
	     {
		int sum = *it+temp;
		sum>9 ?temp=1,sum=0:temp=0;    
		 digits[it-digits.begin()]=sum;
		 if(it == digits.begin() && temp >0)
		{
		    digits.insert(it,temp);
		}
		--it;
	     }
     }
	static void   fun_2(vector<int> & digits,int addnum)
	{
	    auto it = digits.end();
	     --it;
	     int temp=addnum;
	     while( it >= digits.begin())
	     {
		int sum = *it+temp;
		sum>9 ?temp=sum/10:temp=0;    
		 digits[it-digits.begin()]=sum%10;
		 if(it == digits.begin() && temp >0)
		{
		    digits.insert(it,temp);
		}
		--it;
	     }
     }
      static void print_digits(const vector<int> &digits)
      {
	auto it = digits.begin();
	while(it != digits.end())
	{
	 cout<<*it;
	it++;
	}

      }
           

	    


};

int main(char *argv[], int argc)
{
     vector<int> digits;

   digits.push_back(6);
   digits.push_back(6);
   digits.push_back(6);
   Solution::fun_1(digits);
   cout<<endl<<"666+1="; 
   Solution::print_digits(digits);

   digits.clear();
   digits.push_back(6);
   digits.push_back(6);
   digits.push_back(6);
   Solution::fun_2(digits,6);
   cout<<endl<<"666+6=";
   Solution::print_digits(digits);

   digits.clear();
   digits.push_back(6);
   digits.push_back(6);
   digits.push_back(6);
   Solution::fun_2(digits,36);
   cout<<endl<<"666+36=";
   Solution::print_digits(digits);


   digits.clear();
   digits.push_back(6);
   digits.push_back(6);
   digits.push_back(6);
   Solution::fun_2(digits,334);
   cout<<endl<<"666+334=";
   Solution::print_digits(digits);

   digits.clear();
   cout<<endl<<"669+1=";
   digits.push_back(6);
   digits.push_back(6);
   digits.push_back(9);
   Solution::fun_1(digits);
   Solution::print_digits(digits);

   digits.clear();
   cout<<endl<<"999+1=";
   digits.push_back(9);
   digits.push_back(9);
   digits.push_back(9);
   Solution::fun_1(digits);
   Solution::print_digits(digits);
    return 0;
}
    
    

