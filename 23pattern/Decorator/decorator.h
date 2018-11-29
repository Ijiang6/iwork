#ifndef DECORATOR_H
#define DECORATOR_H

class component
{
    public:
        virtual ~component();
        virtual void operation();
    protected:
        component();
    private:
};

class subcomponent:public component
{

    public :
        subcomponent();
        ~subcomponent();
        void operation();
    protected:
    private:
};

class decorator:public component
{
    public:
        decorator(component *com);
        virtual ~decorator();
        void operation();
    protected:
        component *m_pcom;
    private:
};

class subdecorator:public decorator
{
    public:
        subdecorator(component *com);
        ~subdecorator();
        void operation();
        void add();
    protected:
    private:
};
#endif
