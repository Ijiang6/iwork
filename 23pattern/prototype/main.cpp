#include"prototype.h"
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{


    prototype *p=new subprototype();
    prototype *p1=p->clone();
    return0;
}
