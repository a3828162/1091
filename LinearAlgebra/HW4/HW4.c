//#include <opencv2\opencv.hpp>  
#include <opencv2/opencv.hpp>  
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	//Mat Image = imread("ex1.jpg", IMREAD_ANYCOLOR);
	Mat Image = imread(argv[1], IMREAD_ANYCOLOR);
	Mat CannyImg, Imgss;

	cvtColor(Image, Imgss, COLOR_BGR2GRAY);
	GaussianBlur(Imgss, Imgss, Size(5, 5), 0);
	Canny(Imgss, CannyImg, 35, 125);
	vector<vector<Point>> contours;
	findContours(CannyImg, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	int a = 0;
	double max = 0;
	for (int i = 0; i < contours.size(); ++i)
	{
		double tmp = contourArea(contours[i]);
		if (tmp >= max) max = tmp, a = i;
	}
	vector<Point> B = contours[a];
	vector<Point> BF;
	approxPolyDP(B, BF, 3, true);
	auto re = minAreaRect(BF);
	Point2f Box[4];
	re.points(Box);
	
	double x = Box[3].x - Box[0].x, y = Box[3].y - Box[0].y;
	double dis = sqrt(x * x + y * y);

	double o2 = (210.0 * 3752.24) / dis;
	cout << o2 << "\n";
	return 0;
}

/*
	//Mat Image = imread("data.jpg", IMREAD_ANYCOLOR);
	//double _dis = norm(Point(Box[0].x, Box[0].y) - Point(Box[3].x, Box[3].y));

	//double o1 = (dis * 1500.0) / 210.0;
	//double o2 = (210.0 * 3758.2901561693161) / dis;
*/
