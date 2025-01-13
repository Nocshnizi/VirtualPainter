#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
#include"VirtualPainter.h"

using namespace std;
using namespace cv;

Mat img;

void loadPainter(int index) {
	VideoCapture cap(index);

	TracbarCreation();
	while (true) {
		cap.read(img);
		newPoints = findColor(img);
		DrawOnCanvas(newPoints, myColorValues, img);
		imshow("Camera ", img);
		waitKey(1);
	}
	
}