#include"singleton.h"

Sinagleton* Singleton::m_pInstance=NULL;
Singleton::Singleton()
{
  cout<< "create object.."<<endl;
}
Singleton* Singletpn::Instance()
{

    if(m_pInstance ==NULL)
    {

        m_pInstace=new Singleton();
    }
    return m_pOnstance;
}
