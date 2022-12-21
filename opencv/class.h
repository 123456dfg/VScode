#pragma once
#include<iostream>
#include<opencv2/opencv.hpp>
#include<windows.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>
#include<vector>
using namespace std;
using namespace cv;
class demo {
public:
	void contrayp(Mat&);//指针反色
	void contray(Mat&);//反色
	static void ontrack(int, void*);//滚动条回调函数
	void trackingbar(Mat&);//滚动条
	void oncontrast(int, void*);//滚动条反色
	void gray(Mat&);//转灰度图像
	vector<Mat> create_rectangle();//矩形创建
	void bitwise_and(vector<Mat>& mv);
	void bitwise_or(vector<Mat>& mv);
	void bitwise_xor(vector<Mat>& mv);
	void bitwise_not(vector<Mat>& mv);
	void channel_demo(Mat&);//通道分离
	void inrangechange(Mat&);//图像色彩空间转换
	void statisc(Mat&);//像素值统计
	void createshape(vector<Mat>&);//图像几何绘制
	void writepixiv(Mat&);
	void random_drawing();//随机线条
	void writeline();//划线
	void polyline_drawing();//绘制多边形
	void mouse_drawing_demo(Mat& image);//鼠标操作
	static void on_draw(int event, int x, int y, int flags, void* userdata);//鼠标操作回调函数
};