#ifndef FACADE_H
#define FACADE_H

class frame
{
    public:
        frame();
        ~frame();
        void produce();
    protected:
    private:
};

class wheel
{

    public:
        wheel();
        ~wheel();
        void produce();
    protected:
    private:
};


class engine
{
    public:
        engine();
        ~engine();
        void produce();
    protected:
    private:
};


class car
{
    public:
        car();
        ~car();
    void produce();
    protected:
    private:
    frame *pframe;
    wheel *pwheel;
    engine *pengine;
};
#endif






