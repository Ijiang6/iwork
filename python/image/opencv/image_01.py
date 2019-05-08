##图像增强
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


def grayValue(img):
    #灰度直方值
    h,w = img.shape[:2]
    gray=np.zeros([256], np.uint64)
    for i in range(h):
        for j in range(w):
            gray[img[i][j]] +=1

    return gray

image = cv.imread("/home/hacker/1.jpg",0)
grayHist=grayValue(image)
x =np.arange(256)

plt.plot(x,grayHist,'r',linewidth=2, c='black')
plt.xlabel("gray Label")
plt.ylabel("number of pixels")
plt.show()
cv.imshow("img", image)
cv.waitKey()
