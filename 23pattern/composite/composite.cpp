#include"composite.h"

company::company(string str)
{
     m_strname=str;
}
company::~company()
{

}

subcompany::subcompany(string str):company(str)
{
}

subcompany::~subcompany()
{

}
void subcompany::add(company *pcompany)
{
        vector<company *>::iterator it=m_veccompany.find(pcompany);
        if(it == m_veccompany.end())
        {
            m_veccompany.append(pcompany);
        }
}

void subcompany::remove(company *pcompany)
{ 
        vector<company *>::iterator it=m_veccompany.find(pcompany);
        if(it != m_veccompany.end())
        {
            m_veccompany.remove(pcompany);
        }
}


void subcompany::showname()
{
    
        vector<company *>::iterator it=m_veccompany.begin();
        for(;it != m_veccompany.end();it++)
        {
            *it->showname();
        }

}
hrdepartment::hrdepartment(string str):company(str)
{
}
hrdepartment::~hrdepartment()
{
}

hrdepartment::add(company *pcompany)
{
 cout<<"depart ment can not add company"<<endl;
}

hrdepartment::remove(company *pcompany)
{
 cout<<"department have no company"<<endl;
}
hrdepartment::showname()
{
 cout<<"hrdeparment:"<<m_strname<<endl;
}


tecdepartment::add(company *pcompany)
{
 cout<<"depart ment can not add company"<<endl;
}

tecdepartment::remove(company *pcompany)
{
 cout<<"department have no company"<<endl;
}
tecdepartment::showname()
{
 cout<<"tecdeparment:"<<m_strname<<endl;
}

