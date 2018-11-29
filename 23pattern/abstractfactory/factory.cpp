#include"factory.h"
#inlcude<iostream>
using namespace std;

factory::factory()
{
}
factory::~factory()
{
}
factory1::factory1()
{
    cout<<"create factory1"<<endl;
}
factory1::~factory1()
{
}
factory2::factory2()
{
    cout<<"create factory2"<<endl;
}
factory2::~factory2()
{
}

product_a* factory1::create_product_a()
{
    return new product_a1;
}

product_b* factory1::create_product_b()
{
    return new product_b1;
}
product_a* factory2::create_product_a()
{
    return new product_a2;
}

product_b* factory2::create_product_b()
{
    return new product_b2;
}
