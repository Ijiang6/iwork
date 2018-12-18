#include"template.h"

#include<iostream>
using namespace std;
AbstractClass::AbstractClass()
{
}
AbstractClass::~AbstractClass()
{
}

void AbstractClass::TemplateMethod()
{
    fun1();
    fun2();
}

subAbstractClass::subAbstractClass()
{
}
subAbstractClass::~subAbstractClass()
{
}
void subAbstractClass::fun1()
{
 
    cout<<"subAbstractClass fun1"<<endl;
}
void subAbstractClass::fun2()
{
    cout<<"subAbstractClass fun2"<<endl;
}

subAbstractClass2::subAbstractClass2()
{
}
subAbstractClass2::~subAbstractClass2()
{
}
void subAbstractClass2::fun1()
{
 
    cout<<"subAbstractClass2 fun1"<<endl;
}
void subAbstractClass2::fun2()
{
    cout<<"subAbstractClass2 fun2"<<endl;
}
int main(int argc ,char argv[])
{

    AbstractClass *p1= new subAbstractClass();
        p1->TemplateMethod();

    AbstractClass *p2= new subAbstractClass2();
        p2->TemplateMethod();

    delete p1;
    delete p2;
    return 0;
}
