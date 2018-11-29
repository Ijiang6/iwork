#ifndef ADAPTER_H
#define ADAPTER_H

class Target
{
    public:
        Target();
        virtual ~Target();
        virtual void Request();
    protected:
    private:
};

class Adaptee
{
    public:
    Adaptee();
    ~Adaptee();
    void SpecifileRequest();
    protected:
    private:
};
class Adapter:public Target,private Adaptee
{
    public:
        Adapter();
        ~Adapter();
        void Request();
    protected:

    private:
};
#endif


