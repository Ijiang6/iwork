#include "LeetCode.h"


LeetCode::LeetCode(void)
{
}


LeetCode::~LeetCode(void)
{
}
void LeetCode::test()
{
	ListNode Ln1;
	ListNode Ln2;
	ListNode Ln3;
	ListNode Ln4;
	ListNode Ln5;
	ListNode Ln6;
	Ln1.iNum=3;
	Ln1.pNext=&Ln2;

	Ln2.iNum=4;
	Ln2.pNext=&Ln3;

	Ln3.iNum=5;
	Ln3.pNext=NULL;

	Ln4.iNum=3;
	Ln4.pNext=&Ln5;

	Ln5.iNum=6;
	Ln5.pNext=&Ln6;

	Ln6.iNum=5;
	Ln6.pNext=NULL;
	ListNode *LR;
	sumOfTwoListNum(&LR,&Ln1,&Ln4);
	char *str="babad";//abc
	char *str2="cbbd";//b
	char *str3="pwwkew";//wke
	char *sub=NULL;
	
	maxLengthOfSubHWString(&sub,str);
	maxLengthOfSubHWString(&sub,str2);
	int *res=new int;
	int a=-123;
	reversalNum(&res,a);
}
bool LeetCode::sumOfTwoListNum(ListNode ** LNR, ListNode *LN1, ListNode *LN2)
{
	bool bOk=false;
	int iCarry=0;
	int iTempR=0;
	ListNode *LT=NULL;
	while (LN1 !=NULL || LN2 !=NULL)
	{
		int iSum=LN1->iNum+LN2->iNum+iCarry;
		iCarry=iSum/10;

		ListNode *LN=new ListNode();
		LN->iNum=iSum%10;
		LN->pNext=NULL;
		if (LT ==NULL)
		{
			LT=LN;
			*LNR=LT;
		}
		else
		{
			LT->pNext=LN;
			LT=LT->pNext;
		}
		LN1=LN1->pNext;
		LN2=LN2->pNext;	
	}
	//考虑最后的进位
	if (iCarry ==1)
	{
		ListNode *LN=new ListNode();
		LN->iNum=iCarry;
		LN->pNext=NULL;
		LT->pNext=LN;
	}
	if (*LNR != NULL)
	{
		bOk=true;
	}
	return bOk;
}

int LeetCode::maxLengthOfSubstring( char **substr,const char *str)
{
	int iMax=strlen(str);
	if (iMax <1 || iMax ==1)
	{
		return iMax;
	}
	iMax =1;
	char *s=(char*) malloc(1);
	strncpy(s,str,1);
	while(*(str+1) != '\0')
	{
		if ( *(str) == *(str+1))
		{
			if (*s == *str)
			{
				iMax++;
			}
			else
			{
				*s=*str;
			}	
		}
		else
		{
			*substr=NULL;
		}
		str ++;
	}
	if ( *str == *s)
	{
		iMax++;
	}
	*substr =(char *) malloc(sizeof(char)*iMax+1);
	memset(*substr,*s,iMax);
	*(*substr+iMax) ='\0';
	delete s;
	s=NULL;
	return iMax;
}

int LeetCode::maxLengthOfSubstring_2(const char *str)
{
	int asc[256];
	memset(&asc,-1,sizeof(asc));
	const char *left;
	const char *right;
	left =right=str;
	int res=-1;
	for (;(*(str+1) != '\0');str++)
	{
		int iTrun=asc[*str];
		if (iTrun>-1)
		{
			//字符出现过
			left++;
		}
		else
		{
			//字符没有出现过
			//记录字符
			//移动右边界
			asc[*right]=1;
			right++;
		}
		//可能存在 left>right 
		res=std::max(res,right-left);	
	}
	return res;
}

void LeetCode::maxLengthOfSubHWString(char **substr,const char *str)
{
	const char *left;
	const  char *right;
	
	left=right=(str+sizeof(str)/2);
	if (strlen(str)%2 == 0)
	{
		left--;
	}
	while (*left == *right)
	{
		if (*left != *right)
		{
			break;
		}
		left--;
		right++;
	}
	*substr =(char *)malloc(right-left);
	memset(*substr,'\0',right-left);
	int a=right-left;
	strncpy(*substr,left+1,right-left-1);
}
void LeetCode::reversalNum(int ** res,int num)
{
	int iX=1;
	if (num<0)
	{
		iX=-1;
	}
	num=abs(num);
	int i100=num/100;
	int i10=(num-i100*100)/10;
	int i1=num-(100*i100+10*i10);
	**res=iX*(i1*100+10*i10+i100);

}