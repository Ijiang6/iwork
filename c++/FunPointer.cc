#include<iostream>
using namespace std;
typedef int (*funptr) (int ,int);

int add_num(int num_a ,int num_b)
{
    return num_a+num_b;
}

int sub_num(int num_a ,int num_b)
{
    return num_a-num_b;
}
funptr switchfun(char type)
{
    switch(type)
    {
	case'+':return add_num;
	case'-':return sub_num;
    }
}

int funexec(char type,int num_a ,int num_b)
{
    funptr fp = switchfun(type);
    return fp(num_a,num_b);
}
funptr funmap(char type)
{
// 128个数组元素对应128个字符，每个字符对应一个函数
  funptr funmaparray[128]={NULL};
   funmaparray['+']=add_num;
   funmaparray['-']=sub_num;
   return funmaparray[type];
}
funptr funmap2(char type)
{
    int (*funmaparray[128]) (int,int)={NULL};

   funmaparray['+']=add_num;
   funmaparray['-']=sub_num;
   return funmaparray[type];
}
int main(char*argv[],int argc)
{
 
    cout<<"1+2="<<funexec('+',1,2)<<endl;
    cout<<"1-2="<<funexec('-',1,2)<<endl;
 funptr  fp= funmap('+');
    cout<<"1+2="<<fp(1,2)<<endl;
   fp = funmap2('+'); 
    cout<<"1+2="<<fp(1,2)<<endl;
return 0;
}




