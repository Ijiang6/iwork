#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
using namespace std;
class solution
{
    public:
     solution()
        {
            srand((int)time(0));
            for(int itrun=0;itrun <6;itrun++)
            {
                inum[itrun]=random(10);
                cout<<"inum["<<itrun<<"]@"<<inum[itrun]<<endl;
            }

        }
     virtual  ~solution(){}
     void  findIndex(int isum)
     {
         int ires=0;
         for(int itrun=0;itrun<6;itrun++)
             for(int itrun2=itrun+1;itrun2<6;itrun2++)
             {

                 int a=inum[itrun];
                 int b=inum[itrun2];
                 if(a>isum || b>isum)
                 {
                     continue;
                 }
                 if(isum==a+b)
                 {
                     ++ires;
                     cout<<"res="<<ires<<"@"<<itrun<<"#######"<<itrun2<<endl;
                     continue;
                 }

             }
        
     }
 private:
     int inum[6];


};

int main(int argc ,char *argv[])
{
  solution a;
  a.findIndex(10);
  return 0;

}


