#include"decorator.h"
#inlcude<iostream>

using namespace std;

int main(int argc ,char*argv[])
{
    component *pcom=new subcomponent();

    decorator *pdec= new subdecorator(pcom);

    pdec->operation();
    delete pdec;
    return 0;
}
    
