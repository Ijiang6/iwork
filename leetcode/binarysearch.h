#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include<vector>
using namespace std;
class BinarySearch
{
public:
   static bool fun_1(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_2(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_3(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_4(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_5(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_6(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_7(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_LeftBound_1(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_LeftBound_2(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_RightBound_1(const vector<int> & vSrc,const int iKey,int &iIndex);
   static bool fun_RightBound_2(const vector<int> & vSrc,const int iKey,int &iIndex);
   static int  fun_recursive(const vector<int> & vSrc,const int iKey,int iLeft,int iRight);
};

#endif // BINARYSEARCH_H
