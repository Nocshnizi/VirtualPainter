#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include <iostream>
#include"VirtualPainter.h"
#include"Util.hpp"

using namespace std;
using namespace cv;

Point myPoint(0, 0);

Point getContours(Mat image, Mat img) {


	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());



	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;

		string objectType;

		if (area > 1500)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			

			//drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 0), 5);

			if (boundRect[i].x > 0 && boundRect[i].y > 0) {
				return myPoint;
			}			
		}
	}
}


bool detectFace(Mat& img, Mat& imgC, CascadeClassifier& faceCascade, vector<Rect>& faces) {
	if (faceCascade.empty()) { cout << "XML didnt load" << endl; }

	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	equalizeHist(imgGray, imgGray);

	faceCascade.detectMultiScale(imgGray, faces, 1.33, 20, 0, Size(50, 50));

	for (int i = 0; i < faces.size(); i++) {
		rectangle(imgC, faces[i].tl(), faces[i].br(), Scalar(0, 0, 0), 5);
		putText(imgC, "face: " + to_string(i), faces[i].tl(), FONT_HERSHEY_COMPLEX, 0.75, Scalar(255, 255, 255));
	}

	if (faces.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

void ConnectToFace(Point faceDeltaPos, vector<ColouredPoint>& points) {
	for (int i = 0; i < points.size(); i++) {
		points[i].pos += faceDeltaPos;
	}	
}