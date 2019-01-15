#pragma once
#include "LcDataStruct.h"
#include <iostream>
#include <string.h>
#include <string>
#include <assert.h>
class LeetCode
{
public:
	LeetCode(void);
	~LeetCode(void);
	static void test();
	static bool sumOfTwoListNum(ListNode ** LNR, ListNode * LN1, ListNode *LN2);
	static int  maxLengthOfSubstring( char **substr,const char *str);
	static int  maxLengthOfSubstring_2(const char *str);
	static void maxLengthOfSubHWString(char **substr,const char *str);
	static void reversalNum(int ** res,int num);
};

