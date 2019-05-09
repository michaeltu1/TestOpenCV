// TestOpenCV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	// Convert jpg -> bmp and save in exe dir

	// >0 for 3-channel img
	//  0 for greyscale
	// <0 return as is (w/ alpha channel)
	Mat img = imread("sky8k.jpg", 1);
	Mat img_bmp;

	// Primitive type defined in the form 
	// CV_<bit-depth>{U|S|F}C(<number_of_channels>)
	// U = unsigned integer, S = signed integer, F = float
	img.convertTo(img_bmp, CV_8UC3);
	imwrite("sky8k.bmp", img_bmp);

	// Convert bmp -> png and save in exe dir

	Mat img2 = imread("sky8k.bmp", 1);
	//Mat img_png;

    double min, max;
    cv::minMaxLoc(img2, &min, &max);
	
	imwrite("sky8k.png", img2);
	
	// Display image in separate window
	//namedWindow("image", WINDOW_NORMAL);
	//imshow("image", img);
	//waitKey(0);

	// Status
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
