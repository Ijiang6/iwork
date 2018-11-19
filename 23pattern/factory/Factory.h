#ifndef FACTORY_H
#define FACTORY_H
class Product;

class Factory

{

    public:
        virtual ~Factory()=0;
        virtual Product* CreateProduct()=0;
    protected:
        Factory();

};

class SubFactory
{

    public:
        ~SubFactoy();
        Subfactory();
        Product* CreateProduct();
};
#endif


