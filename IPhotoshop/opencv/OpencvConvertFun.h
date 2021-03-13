#ifndef OPENCVCONVERTFUN_H
#define OPENCVCONVERTFUN_H
#include"OpencvInclude.h"
class OpencvConvertFun
{
public:
    static   bool matToImage(const cv::Mat &mat,QImage &image);
    static   bool matBrightnessContrast(const cv::Mat &src, cv::Mat &dst, int alpha,int beta=0);
    static   bool matImageRorateAngle(const cv::Mat &src, cv::Mat &dst,double dAngle);
    static   bool matImageRorateAngleAuto(const cv::Mat &src, cv::Mat &dst);
    static   bool matImageDelFrame(const cv::Mat &src, cv::Mat &dst);
    static   bool matImageDelFrame2(const cv::Mat &src, cv::Mat &dst);

};

#endif // OPENCVCONVERTFUN_H
