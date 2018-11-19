#include"factory.h"
#include<iostream>

using namespace std;

Factory::~Factory(){}

Factory::Factory(){}

SubFactory::~SubFactory(){}


SubFactory::SubFactory()
{

    souct<<"create subFactory"<<endl;
}
Product* SubFactory::CreateProduct()
{
    return new SubProduct();
}

