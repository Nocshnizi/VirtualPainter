#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
#include"VirtualPainter.h"

using namespace std;
using namespace cv;

void DrawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues, Mat img);


int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
vector<vector<int>> newPoints;

vector<vector<int>> myColors {{119, 0, 187, 172, 95, 255}/*purple*/, { 30,35,144,83,255,255 }/*green*/, /*{0,170,149,10,255,255}/*red*/};
vector<Scalar> myColorValues{{232, 173, 166}/*PURPLE*/, { 166, 199, 117 }/*green*/, /*(123, 57, 204)red*/};

vector<vector<int>> findColor(Mat img)
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
		if (myPoint.x != 0) {
			newPoints.push_back({ myPoint.x,myPoint.y,i });
		}
	}
	return newPoints;
}


void DrawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues, Mat img) {
	for (int i = 0; i < newPoints.size(); i++)
	{
		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}

void mouseEvemt(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_RBUTTONDOWN) {
		// Clear the points when right mouse button is clicked
		newPoints.clear();
		cout << newPoints.size()<<endl;
	}
}

void TracbarCreation() {

    namedWindow("Trackbars", (640, 200)); // Create Window
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);
}


