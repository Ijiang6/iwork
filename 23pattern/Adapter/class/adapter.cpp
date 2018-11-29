#include"adapter.h"
#include<iostream>
using namespace std;

Target::Target()
{
}
Target::~Target()
{
}

void Target::Request()
{

    cout<<"target::Request"<<endl;
}

Adaptee::Adaptee()
{
}
Adaptee::~Adaptee()
{
}
void Adaptee::SpecificRequest()
{
    cout<<"Adaptee::SpecificRequest"<<ednl;
}
Adapter::Adapter()
{
}
Adapter::~Adapter()
{
}
void Adapter::Request()
{
    this->SpecificRequest();
}
