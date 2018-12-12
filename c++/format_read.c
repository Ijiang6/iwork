#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)

struct DATA
{
   int num;
   char str[10];
   
};
void struct_write()
{

struct   DATA  data[6];
    srand((int)time(0));
   for(int itrun=0;itrun <6;itrun++)
   {
        
       data[itrun].num=random(100);
        strcpy(data[itrun].str,"data");
    }
   FILE *fp=fopen("./data.txt","wb");
   if(fp==NULL)
   {
        perror("file open error");
        exit(0);
   }
   for(int itrun=0;itrun<6;itrun++)
   {
      int ires= fwrite(&data[itrun],sizeof(struct DATA),1,fp);
      if(ires==0)
      {
          perror("write error");
          continue;
      }
   }
   printf("write success\n");
   fclose(fp);
}
void read_struct()
{
FILE *fp=fopen("data.txt","r");
if(fp==NULL)
    {
        perror("open error");
        exit(0);
    }
struct DATA data;
while(fread(&data,sizeof(struct DATA),1,fp)==1)
{
    printf("read %d # %s \n",data.num,data.str);
}
fclose(fp);
}
void readone()
{
FILE *fp=fopen("data.txt","r");
if(fp==NULL)
    {
        perror("open error");
        exit(0);
    }

struct DATA data;
    fscanf(fp,"%d%s",&data.num,&data.str);
    printf("readone %d # %s \n",data.num,data.str);

}

int main(int argc ,char *argv[])
{

    struct_write();
    read_struct();
    readone();
    return 0;
}



