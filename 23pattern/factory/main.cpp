#include "factory.h"
#include"product.h"
#include"subproduct"
#include<iostream>
using namespace std;

int main(int argc ,char *argv[])
{


    Factory * fac=new SubFactory();
    Procduct *p=fac->CreateProduct();
    return 0;
};
