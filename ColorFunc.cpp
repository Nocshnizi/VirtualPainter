#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
#include"VirtualPainter.h"
#include "Util.hpp"
using namespace std;
using namespace cv;

const vector<vector<int>> myColors {{119, 0, 187, 172, 95, 255}/*purple*/, { 30,35,144,83,255,255 }/*green*/, /*{0,170,149,10,255,255}/*red*/};
const vector<Scalar> myColorValues{{232, 173, 166}/*PURPLE*/, { 166, 199, 117 }/*green*/, /*(123, 57, 204)red*/};

void findColor(bool isTracking, Mat img, vector<ColouredPoint>& points)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++)
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point myPoint = getContours(mask, img);
		
		if (myPoint.x > 0 && !isTracking ) {
			points.push_back({ Point(myPoint.x,myPoint.y),i }); 
			//cout << myPoint << endl;
		}
	}
}


void DrawOnCanvas(bool buttonClicked, vector<ColouredPoint>& points, Mat img) 
{
	if (!buttonClicked) {
		for (int i = points.size() - 1; i > 0; i--)
		{
			circle(img, points[i].pos, 10, myColorValues[points[i].colorIndx], FILLED);
			//cout << points[i].pos << endl; 
		
		}
	}
	else {
		points.clear();
		for (int i = 0; i < points.size(); i++) {
			//cout << points[i].pos << endl;
			
		}
	}

}

void mouseEvent(int event, int x, int y, int flags, void* userdata)
{
	MouseCallbackData* data = (MouseCallbackData*)userdata;

	if (event == EVENT_RBUTTONDOWN) {
		data->buttonClick = true; // Toggle buttonClick
	}
}



