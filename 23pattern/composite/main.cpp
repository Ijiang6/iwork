#include"composite.h"
#include<iostream>
#include<string>
using namespace std;


int main(int argc,char *argv[])
{
    company *pcom=new subcompany("company");
    company *phr=new hrdepartment("hrdepartment");
    company *ptec=new tecdepartment("tecdepartment");
    pcom->add(phr);
    pcom->add(ptec);
    pcom->showname();
    delete pcom;
    delete phr;
    delete ptec;
    return 0;
};
