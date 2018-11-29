#include"decorator.h"
#include<iostream>
using namespace std;
component::component()
{
}

component::~component()
{

}

void component::operation()
{
}

subcomponent::subcomponent()
{
}
subcomponent::~subcomponent()
{
}

void subcomponent::operation()
{
    cout<<"subcomponent operation"<<endl;
}



decorator::decorator(component *com)
{
    m_pcom=com;
}
decorator::~decorator()
{
    delete m_pcom;
}

void decorator::operation()
{
	
}

subdecorator::subdecorator(component *com):decorator(com)
{
}
subdecorator::~subdecorator()
{
}


subdecorator::add()
{
    cout<<"subdecorator::add()"<<endl;
}

void subdecorator::operation()
{
    m_pcom->operation();
    add();
}
