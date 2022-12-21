#pragma once
#include"class.h"
void demo::trackingbar(Mat& image) {
	namedWindow("������Աȶȵ���", WINDOW_FREERATIO);
	int lightness = 50;
	int max = 100;
	int contrastmax = 100;
	int contrast = 0;
	createTrackbar("����", "������Աȶȵ���", &lightness, max, ontrack, (void*)(&image));
	createTrackbar("�Աȶ�", "������Աȶȵ���", &contrast, contrastmax, ontrack, (void*)(&image));

}
void demo::ontrack(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	int max = 100;
	m = Scalar(b, b, b);
	add(image, m, dst);
	imshow("������Աȶȵ���", dst);
}
void demo::oncontrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image, contrast, m, 0, 0, dst);

}
void demo::contrayp(Mat& m1) {//��ɫ(ָ�뷨)
	Mat m2 = m1.clone();
	int w = m1.cols;
	int h = m1.rows;
	int dim = m1.channels();
	if (dim == 1) {//�Ҷ�ͼ��
		for (int row = 0; row < h; row++) {
			uchar* current = m2.ptr<uchar>(row);
			for (int col = 0; col < w; col++) {
				int pv = *current;
				*current = 255 - pv;
			}
		}
	}
	else if (dim == 3) {
		for (int row = 0; row < h; row++) {
			uchar* current = m2.ptr<uchar>(row);
			for (int col = 0; col < w; col++) {
				*current++ = 255 - *current;//�ƶ����κ���һ�����أ���ͨ��
				*current++ = 255 - *current;
				*current++ = 255 - *current;
			}
		}
	}
	namedWindow("ָ��ȡ��", WINDOW_FREERATIO);
	imshow("ָ��ȡ��", m2);
}
void demo::contray(Mat& m) {
	Mat m2;
	m.copyTo(m2);//����ͼ��
	namedWindow("copy", WINDOW_FREERATIO);
	imshow("copy", m2);
	int w = m2.cols;
	int h = m2.rows;
	int dim = m2.channels();
	switch (dim) {
	case 1://�Ҷ�ͼ��
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int current = m2.at<uchar>(i, j);
				m2.at<uchar>(i, j) = 255 - current;
			}
		}
		break;
	case 3:
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int a = m2.at<Vec3b>(i, j)[0];
				int b = m2.at<Vec3b>(i, j)[1];
				int c = m2.at<Vec3b>(i, j)[2];
				m2.at<Vec3b>(i, j)[0] = 255 - m2.at<Vec3b>(i, j)[0];//��ͨ��ȡ��
				m2.at<Vec3b>(i, j)[1] = 255 - m2.at<Vec3b>(i, j)[1];
				m2.at<Vec3b>(i, j)[2] = 255 - m2.at<Vec3b>(i, j)[2];
			}
		}
		break;
	}
	namedWindow("ȡ��", WINDOW_FREERATIO);
	imshow("ȡ��", m2);
}
void demo::gray(Mat& test) {
	Mat M1 = test.clone();
	cvtColor(M1, M1, CV_BGR2GRAY);
	namedWindow("GRAY", WINDOW_FREERATIO);
	imshow("GRAY", M1);
	waitKey(0);
}

vector<Mat> demo::create_rectangle() {
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(230, 230, 0), -1, LINE_8, 0);//B+G
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);//G+R
	vector<Mat>mv;
	mv.push_back(m1);
	mv.push_back(m2);
	return mv;
}
void demo::bitwise_and (vector<Mat>& mv) {
	Mat dst;
	cv::bitwise_and(mv[0],mv[1], dst);
	imshow("�߼���", dst);
}
void demo::bitwise_or(vector<Mat>& mv) {
	Mat dst;
	cv::bitwise_or(mv[0],mv[1], dst);
	imshow("�߼���", dst);
}
void demo::bitwise_xor(vector<Mat>& mv) {
	Mat dst;
	cv::bitwise_xor(mv[0], mv[1], dst);
	imshow("�߼����", dst);
}
void demo::bitwise_not(vector<Mat>& mv) {
	Mat dst,dst1;
	cv::bitwise_not(mv[0], dst);
	imshow("�߼���1", dst);
	cv::bitwise_not(mv[1], dst);
	imshow("�߼���2", dst1);
}
void demo::channel_demo(Mat& m) {
	vector<Mat> mv;
	vector<Mat> mvcopy;
	split(m, mv);//����
	for (auto i = mv.begin(); i != mv.end(); i++)
		mvcopy.push_back(*i);//����ͨ��
	imshow("��ɫ", mv[0]);
	imshow("��ɫ", mv[1]);
	imshow("��ɫ", mv[2]);
	int i;
	while (cin >> i) {
		Mat dst;
		switch (i)
		{
		case 1:mv[0] = 0;
			merge(mv, dst);
			imshow("G+R", dst);
			break;
		case 2:mv[1] = 0;
			merge(mv, dst);
			imshow("B+R", dst);
			break;
		case 3:mv[2] = 0;
			merge(mv, dst);
			imshow("G+R", dst);
			break;
		default:return;
		}
		waitKey(0);
		dst.release();
	}
}
void demo::inrangechange(Mat& m) {
	Mat hsv;
	Mat mask;
	cvtColor(m, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(78, 43, 46), Scalar(99, 255, 255), mask);;
	imshow("mask", mask);
	Mat background = Mat::zeros(m.size(), m.type());
	background = Scalar(255, 150, 150);
	m.copyTo(background, mask);//����ɫΪ0����ɫ�������򻻵�
	imshow("������", background);
}
void demo::statisc(Mat& m) {
	int channels = m.channels();
	vector<Mat>cv;
	split(m, cv);
	for (int i = 0; i < channels; i++)
	{
		double minv, maxv;
		Point minLoc, maxLoc;
		minMaxLoc(m, &minv, &maxv, &minLoc, &maxLoc);//�����������Сֵ(��ͨ��)
		cout << "min value:" << minv << "max value" << maxv << endl;
		
	}
	Mat avr, stddev;
	meanStdDev(m, avr, stddev);
	cout << "ƽ��ֵ:" << avr << "��׼����" << stddev << endl;
}
void demo::createshape(vector<Mat>& m) {
	Rect rect;//���ζ���
	rect.x = 50;//������ʼ��x
	rect.y = 50;//������ʼ��y
	rect.width = 100;//���ο�
	rect.height = 100;//���θ�
	rectangle(m[0], rect, Scalar(0, 255, 0), 2, 8, 0);
	circle(m[0], Point(100, 100), 15, Scalar(255, 0, 0), 1, 0);//����Բ
	line(m[0], Point(100, 100), Point(150, 150), Scalar(0, 0, 255), 2, 8, 0);
	Mat dst;
	addWeighted(m[0], 0.7, m[1], 0.3,0,dst);
	RotatedRect rrt;
	rrt.center = Point(75, 75);
	rrt.size = Size(150, 100);
	rrt.angle = 0;
	ellipse(dst, rrt, Scalar(100, 100, 100),1,8);
	imshow("����ͼ��", dst);

}
void demo::writepixiv(Mat&m) {
	string filename,path;
	int flag;
	filename = "image.jpg";
	path = "";
	cin >> flag;
	cout << "1.Ĭ��λ�ú�����   2.�Զ���λ�ú�����" << endl;
	switch (flag) {
	case 1:break;
	case 2:
		cout << "�������ļ���" << endl;
		cin >> filename;
		cout << "�����뱣��λ��" << endl;
		cin >> path;
		break;
	}
	imwrite(path+'/'+filename, m);
}
void demo::random_drawing() {
	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
	int w = canvas.cols;
	int h = canvas.rows;
	RNG rng(12345);
	while (1) {
		char c=waitKey(10);
		if (c == '\r') {
			destroyAllWindows();
			break;
		}
		int x1 = rng.uniform(0, w);
		int y1 = rng.uniform(0, h);
		int x2 = rng.uniform(0, w);
		int y2 = rng.uniform(0, h);
		int g = rng.uniform(0, 255);
		int b = rng.uniform(0, 255);
		int r = rng.uniform(0, 255);
		line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 1, LINE_AA, 0);
		imshow("canvas", canvas);
	}
	
}
void demo::writeline() {
	Mat m = Mat::zeros(Size(300, 300), CV_8UC3);
	line(m, Point(0, 0), Point(300, 300), Scalar(0, 0, 255), 1, 8, 0);
	imshow("m", m);
	waitKey(0);
}
void demo::polyline_drawing() {
	Mat poly = Mat::zeros(Size(512, 512), CV_8UC3);
	Point p[8] = { Point(100, 100), Point(100, 150), Point(170, 200), Point(252, 200), Point(300, 300),Point(360, 360),Point(512, 512), Point(0, 0) };
	vector<Point>vp;
	for (int i = 0; i < 8; i++) {
		vp.push_back(p[i]);
	}
	fillPoly(poly, vp, Scalar(255, 0, 0),8, 0);//�������
	polylines(poly, vp, true, Scalar(255, 255, 255), 2, 8, 0);//���߶����
	imshow("����λ���", poly);
}
Point sp(-1, -1);
Point ep(-1, -1);
Mat temp;
void demo::mouse_drawing_demo(Mat& image) {
	namedWindow("������", WINDOW_AUTOSIZE);
	setMouseCallback("������", on_draw,(void*)(&image));
	imshow("������", image);
	temp = image.clone();
}
void demo::on_draw(int event,int x,int y,int flags,void *userdata) {
	Mat image = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {
		sp.x = x;
		sp.y = y;
		cout << "start point=" << sp << endl;
	}
	else if (event == EVENT_LBUTTONUP) {
		ep.x = x;
		ep.y = y;
		int dx = ep.x - sp.x;
		int dy = ep.y - sp.y;
		Rect box(sp.x, sp.y, dx, dy);
		if (dx > 0 && dy > 0) {
			rectangle(image, box, Scalar(0, 0, 255), 2, LINE_AA, 0);
			imshow("roi����", image(box));
			imshow("������", image);
			//reset
			sp.x = -1;
			sp.y = -1;
		}
	}
	else if (event == EVENT_MOUSEMOVE) {
		if (sp.x > 0 && sp.y > 0) {
			ep.x = x;
			ep.y = y;
			int dx = ep.x - sp.x;
			int dy = ep.y - sp.y;
			if (dx > 0 && dy > 0) {
				Rect box(sp.x, sp.y, dx, dy);
				temp.copyTo(image);
				rectangle(image, box, Scalar(0, 0, 255), 2, LINE_AA, 0);
				imshow("������", image);
			}
		}
	}
}