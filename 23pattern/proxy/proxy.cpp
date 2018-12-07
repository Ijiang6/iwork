#include"proxy.h"
#include<iostream>
using namespace std;

subject::subject()
{
}
subject::~subject()
{
}
subject1::subject1()
{
}
subject1::~subject1()
{
}

void subject1::request()
{

    cout<<"subject1@request"<<endl;

}

proxy::proxy(subject *sub)
{
    psub=sub;
}
proxy::~proxy()
{
    delete psub;
}
void proxy::request()
{
    cout<<"proxy@request"<<endl;
    psub->request();
}

int main(int argc ,char*argv[])
{
    subject *psub=new subject1();
    proxy *p=new proxy(psub);
    p->request();
    return 0;
}




