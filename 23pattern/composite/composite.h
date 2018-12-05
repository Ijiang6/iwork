#ifndef COMPOSITE_H
#define COMPOSITE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class company
{
 public:
     virtual ~company();
     virtual void add(company *pcompany)=0;
     virtual void remove(company *pcompany)=0;
     virtual void showname()=0;
 protected:
     company(string str);
 private:
     string m_strname;

};
class subcompany:public company
{
    public:
        subcompany(string str);
        ~subcompany();
        void add(company *pconpany);
        void remove(company *pconpany);
        void showname();
    private:

        vector<company *> m_veccompany;
};

class hrdepartment:public company
{
public:
    hrdepartment(string str);
    ~hrdepartment();
    void add(company *pcompany);
    void remove(company *pcompany);
    void showname();


};

class tecdepartment:public company
{
public:
    tecdepartment(string str);
    ~tecdepartment();
    void add(company *pcompany);
    void remove(company *pcompany);
    void showname();


};
#endif

