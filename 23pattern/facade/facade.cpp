#include"facade.h"
#include<iostream>
using namespace std;
frame::frame()
{
}
frame::~frame()
{
}

void frame::produce()
{
    cout<<"produce @frame"<<endl;
}

wheel::wheel()
{
}

wheel::~wheel()
{
}

void wheel::produce()
{

    cout<<"produce @ wheel"<<endl;
}


engine::engine()
{
}
engine::~engine()
{

}
void engine::produce()
{

    cout<<"produce@ engine"<<endl;

}

car::car()
{
    pframe=new frame();
    pwheel=new wheel();
    pengine=new engine();

}

car::~car()
{
    delete pframe;
    delete pwheel;
    delete pengine;
}

void car::produce()
{
    pframe->produce();
    pwheel->produce();
    pengine->produce();
}

int main(int argc ,char *argv[])
{

    car *pcar=NULL;
    pcar=new car();

    if(pcar)
    {
        pcar->produce();
    }
    return 0;
}
    




