#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class prototype
{
    public:
        virtual ~prototype();
        virtual const prototype * clone()=0;
    protected:
    private:

};
class subprototype:public prototype
{

    public:
    subprototype();
    subprototype(const subprototype &cp);
    ~subprototype();
  const  prototype* clone();
  protected:
  private:
};
#endif

