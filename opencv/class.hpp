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
	void contrayp(Mat&);//ָ�뷴ɫ
	void contray(Mat&);//��ɫ
	static void ontrack(int, void*);//�������ص�����
	void trackingbar(Mat&);//������
	void oncontrast(int, void*);//��������ɫ
	void gray(Mat&);//ת�Ҷ�ͼ��
	vector<Mat> create_rectangle();//���δ���
	void bitwise_and(vector<Mat>& mv);
	void bitwise_or(vector<Mat>& mv);
	void bitwise_xor(vector<Mat>& mv);
	void bitwise_not(vector<Mat>& mv);
	void channel_demo(Mat&);//ͨ������
	void inrangechange(Mat&);//ͼ��ɫ�ʿռ�ת��
	void statisc(Mat&);//����ֵͳ��
	void createshape(vector<Mat>&);//ͼ�񼸺λ���
	void writepixiv(Mat&);
	void random_drawing();//�������
	void writeline();//����
	void polyline_drawing();//���ƶ����
	void mouse_drawing_demo(Mat& image);//������
	static void on_draw(int event, int x, int y, int flags, void* userdata);//�������ص�����
};