#pragma once
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>

struct ColouredPoint
{
	cv::Point pos = cv::Point(0,0);
	int colorIndx = 0;
};