#include "OpencvConvertFun.h"

#include<vector>
//CV_8SC1 :8位无符号整型单通道矩阵
//CV_32FC2:32位浮点型双通道矩阵
bool OpencvConvertFun::matToImage(const cv::Mat &mat, QImage &imageDst)
{
    bool bSuccess = false;
    if( mat.type() == CV_8SC1)
    {
        QImage image(mat.cols,mat.rows,QImage::Format_Indexed8);//the image is stored using 8-bit indexes into a colormap.
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
            // Copy input Mat
            uchar *pSrc = mat.data;
            for(int row = 0; row < mat.rows; row ++)
            {
                uchar *pDest = image.scanLine(row);
                memcpy(pDest, pSrc, mat.cols);
                pSrc += mat.step;
            }
            imageDst= image;
        }

    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, (int)mat.step, QImage::Format_RGB888);
        imageDst = image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        //qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, (int)mat.step, QImage::Format_ARGB32);
        imageDst = image.copy();

    }

    return bSuccess;

}
/**
 * @brief OpencvConvertFun::matBrightness
 * @param src
 * @param dst
 * @param value
 * @return
 */
bool OpencvConvertFun::matBrightnessContrast(const cv::Mat &src, cv::Mat &dst, int alpha,int beta)
{
    dst = cv::Mat::zeros(src.size(),src.type());

    int width = src.cols;
    int height = src.rows;
    int channels = src.channels();

    for(int w = 0; w< width ;++ w)
    {
        for(int h = 0;h<height;++h)
        {
            if (channels == 3)     //如果是彩色图像
            {
                dst.at<cv::Vec3b>(h, w)[0] = cv::saturate_cast<uchar>(alpha*(src.at<cv::Vec3b>(h, w)[0]) + beta);
                dst.at<cv::Vec3b>(h, w)[1] = cv::saturate_cast<uchar>(alpha*(src.at<cv::Vec3b>(h, w)[1]) + beta);
                dst.at<cv::Vec3b>(h, w)[2] = cv::saturate_cast<uchar>(alpha*(src.at<cv::Vec3b>(h, w)[2]) + beta);
            }
            else if (channels == 1)  //灰度图像
            {
                dst.at<uchar>(h, w) = cv::saturate_cast<uchar>(alpha*(src.at<uchar>(h, w)) + beta);

            }
        }
    }
    return !dst.empty();

}
/**
 * @brief OpencvConvertFun::matImageRorateAngle
 * @param src
 * @param dst
 * @return
 */
bool OpencvConvertFun::matImageRorateAngle(const cv::Mat &src, cv::Mat &dst,double dAngle)
{

        std::vector<cv::Point> vPoints;
        cv::Mat gray;
        cv::cvtColor(src,gray,cv:: COLOR_BGR2GRAY);
        cv::findNonZero(gray,vPoints);
        cv::RotatedRect box = cv::minAreaRect(cv::Mat(vPoints));

        cv::Mat rot_mat = cv::getRotationMatrix2D(box.center, dAngle, 1);
        //仿射变换
        cv::warpAffine(src, dst, rot_mat, src.size(), cv::INTER_CUBIC, 0, cv::Scalar(255, 255, 255));
        return !dst.empty();
}
/**
 * @brief OpencvConvertFun::matImageRorateAngleAuto
 * @param src
 * @param dst
 * @return
 */
bool OpencvConvertFun::matImageRorateAngleAuto(const cv::Mat &src, cv::Mat &dst)
{
    int threshold_value = 100;
    cv::Mat gray;
    cv::cvtColor(src,gray,cv::COLOR_RGB2GRAY);

    cv::Mat candyimg;
    //边缘检测
    cv::Canny(gray,candyimg,threshold_value,threshold_value*2,3);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i>hireachy;
    cv::findContours(candyimg,contours,hireachy,cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE);
    cv::Mat drawImg  = cv::Mat::zeros(src.size(),src.type());

    float max_width = 0 ;
    float max_height = 0 ;
    double degree = 0 ;
    for(int index = 0 ; index < contours.size() ; ++ index)
    {
        cv::RotatedRect minRect = cv::minAreaRect(contours[index]);
        degree = std::abs(minRect.angle);
        if( degree >0)
        {
            max_width = std::max(max_width,minRect.size.width);
            max_height = std::max(max_height,minRect.size.height);
        }
    }
    cv::RNG rng(12345);
    for(int index = 0 ; index < contours.size() ; ++ index)
    {
        cv::RotatedRect minRect = cv::minAreaRect(contours[index]);
        if(max_width == minRect.size.width && max_height == minRect.size.height)
        {
            degree = minRect.angle;
            cv::Point2f pts[4];
            minRect.points(pts);
            cv::Scalar color = cv::Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
            for(int i = 0 ; i< 4 ;++i)
            {
                cv::line(drawImg,pts[i],pts[(i+1)%4],color,2);
            }
        }
    }
    cv::Point2f center(src.rows/2, src.cols/2);
    cv::Mat rotm = cv::getRotationMatrix2D(center,degree,1.0);
    cv::warpAffine(src,dst,rotm,src.size(),cv::INTER_LINEAR,0,cv::Scalar(255,255,255));
    return !dst.empty();
}
/**
 * @brief OpencvConvertFun::matImageDelFrame
 * @param src
 * @param dst
 * @return
 */
bool OpencvConvertFun::matImageDelFrame(const cv::Mat &src, cv::Mat &dst)
{
  int threshold_value  =100;
        //先转换成灰度图像
  cv::Mat gray_src;
  cv::cvtColor(src, gray_src, CV_BGR2GRAY);

        //Canny检测，采用是L1计算方式（false）
        cv:: Mat canny_output;
       cv:: Canny(gray_src, canny_output, threshold_value, threshold_value * 2, 3, false);

        //定义数组存放检测到外形信息，在进行轮廓发现，这会有很多轮廓
        std::vector<std::vector<cv::Point>>contours;
        std::vector<cv::Vec4i>hireachy;
        cv::findContours(canny_output, contours, hireachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

        //定义轮廓的外接矩形最小的宽度和长度
        int minw = src.cols*0.75;
        int minh = src.rows*0.75;

        //定义随机数
        cv::RNG rng(12345);

        //定义矩形承接合适轮廓的最小外接矩形
        cv::Rect bbox;

        //定义模板用于把轮廓画出来
        cv::Mat drawImage = cv::Mat::zeros(src.size(), src.type());

        for (size_t t = 0; t < contours.size(); t++) {
            //寻找每个轮廓的最小的外接矩形，这个矩形可以使多角度的。
            cv::RotatedRect minRect = cv::minAreaRect(contours[t]);
 bbox = minRect.boundingRect();
            //判断最小的矩形是否大于最小宽度和高度
            if(minRect.size.width > minw && minRect.size.height > minh&& minRect.size.width < (src.cols - 5)) {

                //提取4个角的信息
                cv::Point2f pts[4];
                minRect.points(pts);
                bbox = minRect.boundingRect();
                cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
                //绘制4个点的连线，0,1,2,3。没有4，所以第二点对4 取模即可。
                for (int i = 0; i < 4; i++) {
                    line(drawImage, pts[i], pts[(i + 1) % 4], color, 2, 8, 0);
                }
            }
        }


        //显示最后的切边的成图
        if (bbox.width > 0 && bbox.height > 0) {
             dst = src(bbox);
        }
        return  !dst.empty();
}
/**
 * @brief OpencvConvertFun::matImageDelFrame2
 * @param src
 * @param dst
 * @return
 */
bool OpencvConvertFun::matImageDelFrame2(const cv::Mat &src, cv::Mat &dst)
{


    //灰度化
    cv::Mat grayImage;
    cv::cvtColor(src,grayImage,CV_BGR2GRAY);

    //二值化原图像
    cv::Mat thresImage=cv::Mat::zeros(grayImage.rows,grayImage.cols,CV_8UC1);
    cv::threshold(grayImage,thresImage,127,255,cv::THRESH_BINARY);
    //imshow("thresImage",thresImage);

    const int nr=thresImage.rows;
    const int nc=thresImage.cols;
    cv::Mat edge[4];
    edge[0] = thresImage.row(0);    //up
    edge[1] = thresImage.row(nr-1); //bottom
    edge[2] = thresImage.col(0);    //left
    edge[3] = thresImage.col(nc-1); //right

    std::vector<cv::Point> edgePts;
    const int minLength=std::min(nr,nc)/4;
    for(int i=0;i<4;++i)
    {
        std::vector<cv::Point> line;
        cv::Mat_<uchar>::const_iterator iter = edge[i].begin<uchar>();       //当前像素
        cv::Mat_<uchar>::const_iterator nextIter = edge[i].begin<uchar>()+1; //下一个像素
        while(nextIter!=edge[i].end<uchar>())
        {
            if(*iter==255)
            {
                if(*nextIter==255)
                {
                    cv::Point pt = iter.pos();

                    if(i==1)
                        pt.y = nr-1;
                    if(i==3)
                        pt.x = nc-1;

                    line.push_back(pt);
                }
                if(*nextIter!=255)
                {
                    if(line.size()>minLength)
                        edgePts.push_back(line.at(line.size()/2));
                    line.clear();
                }
            }
            ++iter;
            ++nextIter;
        }
    }


  return  !dst.empty();
}

