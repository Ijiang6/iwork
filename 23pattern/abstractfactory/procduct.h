#ifndef PROCDUCT_H
#define PROCDUCT_H

class procduct_a
{
    public:
        virtual ~product_a();
    protected:
        product_a();
    private:

};

class product_b
{
    public:
        virtual ~product_b();
    protected:
        product_b();
    private:


};

class product_a1:public product_a
{
  public:
      product_a1();
      ~product_a1();

};
class product_b1:public product_b
{
  public:
      product_b1();
      ~product_b1();

};
class product_a2:public product_a
{
  public:
      product_a2();
      ~product_a2();

};
class product_b2:public product_b
{
  public:
      product_b2();
      ~product_b2();

};
#endif
