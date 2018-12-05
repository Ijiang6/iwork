#include<vector>
#include<iterator>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(int argc,char *argv[])
{

    map<int,vector<string>> imap;
    vector<string> vecstr;
    
    imap[1]=vecstr;
    map<int,vector<string>>:: iterator it=imap.find(1);
    if(it != imap.end())
    {
        cout<<it->first<<endl;
    }
    vector<string>:: iterator  it2=vecstr.begin();
    if(it2 != vecstr.end())
    {
    cout<< *it2<<endl;

    }

     return 0;
}
