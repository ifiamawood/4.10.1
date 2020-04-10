// 4.10.1.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h" 
 #include <iostream>
 #include <opencv2/opencv.hpp>
 using namespace cv;
 using std::string;

 int main()
 {
	 cv::Mat out;
	 cv::Mat in = imread("D:\\10.png", 1);
	 if (in.empty()) return -1;
	 Canny(in, out, 50, 200, 3);
	 std::vector<cv::Vec2f> lines;
	 HoughLines(out,lines,1,CV_PI/180,100,0,0);
	 std::vector<cv::Vec2f>::iterator it = lines.begin();
	 for (; it != lines.end(); ++it) {
		 float rho = (*it)[0], theta = (*it)[1];
		 cv::Point pi, p2;
		 double a = cos(theta);
		 double b = sin(theta);
		 double x = a*rho;
		 double y = b*rho;
		 pi.x = saturate_cast<int>(x + 1000 * (-b));
		 pi.y = saturate_cast<int>(y + 1000 * (a));
		 p2.x = saturate_cast<int>(x - 1000 * (-b));
		 p2.y = saturate_cast<int>(y - 1000 * (a));
		 line(in, pi, p2, Scalar(0, 0, 255), 1, CV_AA);
	 }
	 imshow("output", in);
	 waitKey(0);
	 }


