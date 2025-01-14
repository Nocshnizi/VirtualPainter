#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
#include"VirtualPainter.h"

using namespace std;
using namespace cv;

Mat img, imgF, imgC;


void loadPainter(int index) {
	VideoCapture cap(index);

	namedWindow("Camera");
	setMouseCallback("Camera", mouseEvemt);

	TracbarCreation();
	while (true) {
		cap.read(img);
		flip(img, imgF, 1);
		imgF.copyTo(imgC);
		newPoints = findColor(imgC);		
		DrawOnCanvas(newPoints, myColorValues, imgC);
		if (newPoints.empty()) { imgF.copyTo(imgC); }
		imshow("Camera", imgC);
		int k = waitKey(1);
		if (k == 27) {			
			exit(0);
		}
	}
	
}