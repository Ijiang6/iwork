#include "CGlobal.h"

CGlobal::CGlobal()
{

}
CGlobal* CGlobal::pInstance=nullptr;
CGlobal *CGlobal::getInstance()
{
    if( pInstance == nullptr)
    {
        pInstance = new CGlobal;
    }
    return pInstance;

}
