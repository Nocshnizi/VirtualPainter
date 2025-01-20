#pragma once
#ifndef VIRTUALPAINTER_H // Include guard
#define VIRTUALPAINTER_H

#include "Util.hpp"

using namespace std;
using namespace cv;


void loadPainter(int index);
void findColor(bool isTracking, Mat img, vector<ColouredPoint>& points);
void DrawOnCanvas(bool buttonClicked, vector<ColouredPoint>& points, Mat img);
Point getContours(Mat image, Mat img);
void mouseEvent(int event, int x, int y, int flags, void* userdata);
bool detectFace(Mat& img, Mat& imgC, CascadeClassifier& faceCascade, vector<Rect>& faces);
void ConnectToFace(Point faceDeltaPos, vector<ColouredPoint>& points);
void UI(Mat& img);
#endif // VIRTUALPAINTER_H