#include"factory.h"
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{

    factory *f1=new factory1();
    f1->create_product_a();
    f1->create_product_b();


    factory *f2=new factory2();
    f2->create_product_a();
    f2->create_product_b();

    return 0;

}
