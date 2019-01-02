#pragma once
#include <stdio.h>
#include <stdlib.h>
static int iNum=0;
class CBuild_Delect
{
public:
	CBuild_Delect(void);
	CBuild_Delect(const CBuild_Delect &obj);
	~CBuild_Delect(void);
	void disploy();
	CBuild_Delect&  operator = (const CBuild_Delect &obj)
	{
		iNum++;
		*this=obj;
		return *this;

	}
};
void check(CBuild_Delect obj);


