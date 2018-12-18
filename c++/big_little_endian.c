#include<stdio.h>
#include<stdlib.h>
int check_system()
{
    union ucheck
    {
        int i;
        char ch;
    }u;

    u.i=1;

    return (u.ch ==1);
}
int main(int argc ,char *argv[])
{
    if(check_system())
    {

    printf(" this system is little endian\n");
    }
    else
    {

    printf(" this system is big endian\n");
    }
    return 0;
}

