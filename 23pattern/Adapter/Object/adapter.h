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
class Adapter:public Target
{
    public:
        Adapter(const Adaptee *ade);
        ~Adapter();
        void Request();
    protected:

    private:
        Adaptee *m_pAde;
};
#endif


