#include"prototype.h"
#include<iostream>
using namespace std;


prototype::prototype()
{
}
prototype::~prototype()
{
}
const prototype* prototype::clone()
{
    prototype *Pt=NULL;
    return pt;
}
subprototype::subprototype()
{
}
subprototype::~subprototype()
{
}
const subprototype* subprototype::clone()
{
    prototype *Pt=new subprototype(*this);
    return pt;
}
subprototype::subprototype(const subprototype &cp)
{
    cout<<"subprototype copy......"<<endl;

}

