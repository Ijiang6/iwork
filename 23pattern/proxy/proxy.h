#ifndef PROXY_H
#define PROXY_H

class subject
{
    public:
        virtual ~subject();
        virtual void request()=0;
    protected:
        subject();
};
class subject1:public subject
{

    public:
        subject1();
        ~subject1();
        void request();
};

class proxy
{
    public:
    proxy(subject *sub);
    ~proxy();
    void request();
    private:
    subject *psub;

};
#endif


