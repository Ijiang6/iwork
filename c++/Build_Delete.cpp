#include "Build_Delete.h"


CBuild_Delect::CBuild_Delect(void)
{
	printf("build->%d\n",iNum);
}

CBuild_Delect::CBuild_Delect(const CBuild_Delect &obj)
{
	*this=obj;

}
CBuild_Delect::~CBuild_Delect(void)
{
	printf("delete->%d\n",iNum);
}
void CBuild_Delect::disploy()
{
	printf("delete->%d\n",iNum);
}
void check(CBuild_Delect obj)
{
	CBuild_Delect obj2;
	obj2=obj;
	obj.disploy();
}
int main(int argc, char *argv[])
{
	CBuild_Delect obj;
	CBuild_Delect obj2=obj;
	check(obj);
}