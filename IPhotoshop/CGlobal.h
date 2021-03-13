#ifndef CGLOBAL_H
#define CGLOBAL_H
#include"OpencvInclude.h"
#include"OpencvConvertFun.h"
class CGlobal
{
public:
    CGlobal();
   static  CGlobal* getInstance();
public:
    cv::Mat g_MatSrc;
    cv::Mat g_MatDst;
private:
    static CGlobal *pInstance;
};

#endif // CGLOBAL_H
