#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
#include"VirtualPainter.h"
#include"Util.hpp"

void UI(Mat& img) {
	putText(img, "Press 't' to connect your image to face ", Point(10, 10), FONT_HERSHEY_COMPLEX, 0.4, Scalar(255, 255, 255));
	putText(img, "Press 'c' to clear screen ", Point(10, 25), FONT_HERSHEY_COMPLEX, 0.4, Scalar(255, 255, 255));
	putText(img, "Warning!: You can't draw while tracking", Point(350, 460), FONT_HERSHEY_COMPLEX, 0.4, Scalar(0, 0, 255), 2); // Shadow
	putText(img, "Warning!: You can't draw while tracking", Point(350, 460), FONT_HERSHEY_COMPLEX, 0.4, Scalar(255, 255, 255), 1); // Text
}
