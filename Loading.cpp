#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/dnn.hpp>
#include <iostream>
#include "VirtualPainter.h"
#include "Util.hpp"

using namespace std;
using namespace cv;

const string cascade = "Source/haarcascade_frontalface_default.xml";


void loadPainter(int index) {
	VideoCapture cap(index);
	CascadeClassifier faceCascade;
	faceCascade.load(cascade);
	namedWindow("Camera");
	

	Mat img, imgF;
	bool isTracking = false;
	vector<ColouredPoint> points;
	vector<Rect> faces;
	Point lastFacePos(0, 0);

	setMouseCallback("Camera", mouseEvent, &points,);

	while (true) {
		cap.read(img);
		flip(img, imgF, 1);
		Mat imgC = imgF.clone();

		findColor(isTracking, imgC, points);		
		DrawOnCanvas(points, imgC);
		detectFace(imgF, imgC, faceCascade, faces);
				
		imshow("Camera", imgC);

		if (points.empty()) { imgF.copyTo(imgC); }
		int k = waitKey(1);		
		if (k == 't' && !faces.empty()) {
			isTracking = !isTracking;
			lastFacePos = Point(faces[0].x, faces[0].y);
		}

		if (isTracking && !faces.empty()) {
			Point faceDeltaPos = Point(faces[0].x, faces[0].y) - lastFacePos;

			//calc
			ConnectToFace(faceDeltaPos, points);

			lastFacePos = Point(faces[0].x, faces[0].y);
		}

		if (k == 27) { exit(0); }
	}
	
}