#ifndef FACTORY_H
#define FACTORY_H
class product_a;
class product_b;

class factory
{
    public :
    virtual ~factory();

    virtual product_a* create_product_a()=0;
    virtual product_b* create_product_b()=0;
    protected:
    factory();
    private:

};

class factory1:public factory
{
 public:
     factory1();
     ~factory1();
     product_a * create_product_a();
     product_b * create_product_b();
protected:
private:

};
class factory2:public factory
{
    public:
        factory2();
        ~factory2();
        
     product_a * create_product_a();
     product_b * create_product_b();

};
#endif
