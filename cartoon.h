#ifndef CARTOON_H
#define CARTOON_H

#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;

void cartoonifyImage(Mat &srcColor,  Mat &dst, bool evilMode, bool sketchMode);
void removePepperNoise(Mat &mask);

#endif // CARTOON_H
