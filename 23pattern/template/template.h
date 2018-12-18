#ifndef TEMPLATE_H
#define TEMPLATE_H

class AbstractClass
{
    public:
        virtual ~AbstractClass();
        void TemplateMethod();
    protected:
        virtual void fun1()=0;
        virtual void fun2()=0;
        AbstractClass();
    private:
};

class subAbstractClass:public AbstractClass
{
    public:
        subAbstractClass();
        ~subAbstractClass();
    protected:
        void fun1();
        void fun2();
    private:
};
class subAbstractClass2:public AbstractClass
{
    public:
        subAbstractClass2();
        ~subAbstractClass2();
    protected:
        void fun1();
        void fun2();
    private:
};
#endif
