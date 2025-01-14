#pragma once
#ifndef VIRTUALPAINTER_H // Include guard
#define VIRTUALPAINTER_H
using namespace std;
using namespace cv;

extern vector<vector<int>> newPoints;
extern vector<Scalar> myColorValues;

void loadPainter(int index);
void TracbarCreation();
vector<vector<int>> findColor(Mat img);
void DrawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues, Mat img);
Point getContours(Mat image, Mat img);
void mouseEvemt(int event, int x, int y, int flags, void* userdata);

#endif // VIRTUALPAINTER_H