#pragma once
#include"class.h"
void demo::trackingbar(Mat& image) {
	namedWindow("亮度与对比度调整", WINDOW_FREERATIO);
	int lightness = 50;
	int max = 100;
	int contrastmax = 100;
	int contrast = 0;
	createTrackbar("亮度", "亮度与对比度调整", &lightness, max, ontrack, (void*)(&image));
	createTrackbar("对比度", "亮度与对比度调整", &contrast, contrastmax, ontrack, (void*)(&image));

}
void demo::ontrack(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	int max = 100;
	m = Scalar(b, b, b);
	add(image, m, dst);
	imshow("亮度与对比度调整", dst);
}
void demo::oncontrast(int b, void* userdata) {
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image, contrast, m, 0, 0, dst);

}
void demo::contrayp(Mat& m1) {//反色(指针法)
	Mat m2 = m1.clone();
	int w = m1.cols;
	int h = m1.rows;
	int dim = m1.channels();
	if (dim == 1) {//灰度图像
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
				*current++ = 255 - *current;//移动三次后下一个像素，三通道
				*current++ = 255 - *current;
				*current++ = 255 - *current;
			}
		}
	}
	namedWindow("指针取反", WINDOW_FREERATIO);
	imshow("指针取反", m2);
}
void demo::contray(Mat& m) {
	Mat m2;
	m.copyTo(m2);//复制图像
	namedWindow("copy", WINDOW_FREERATIO);
	imshow("copy", m2);
	int w = m2.cols;
	int h = m2.rows;
	int dim = m2.channels();
	switch (dim) {
	case 1://灰度图像
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
				m2.at<Vec3b>(i, j)[0] = 255 - m2.at<Vec3b>(i, j)[0];//三通道取反
				m2.at<Vec3b>(i, j)[1] = 255 - m2.at<Vec3b>(i, j)[1];
				m2.at<Vec3b>(i, j)[2] = 255 - m2.at<Vec3b>(i, j)[2];
			}
		}
		break;
	}
	namedWindow("取反", WINDOW_FREERATIO);
	imshow("取反", m2);
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
	imshow("逻辑与", dst);
}
void demo::bitwise_or(vector<Mat>& mv) {
	Mat dst;
	cv::bitwise_or(mv[0],mv[1], dst);
	imshow("逻辑或", dst);
}
void demo::bitwise_xor(vector<Mat>& mv) {
	Mat dst;
	cv::bitwise_xor(mv[0], mv[1], dst);
	imshow("逻辑异或", dst);
}
void demo::bitwise_not(vector<Mat>& mv) {
	Mat dst,dst1;
	cv::bitwise_not(mv[0], dst);
	imshow("逻辑非1", dst);
	cv::bitwise_not(mv[1], dst);
	imshow("逻辑非2", dst1);
}
void demo::channel_demo(Mat& m) {
	vector<Mat> mv;
	vector<Mat> mvcopy;
	split(m, mv);//分离
	for (auto i = mv.begin(); i != mv.end(); i++)
		mvcopy.push_back(*i);//拷贝通道
	imshow("蓝色", mv[0]);
	imshow("绿色", mv[1]);
	imshow("红色", mv[2]);
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
	m.copyTo(background, mask);//把颜色为0（黑色）的区域换掉
	imshow("换背景", background);
}
void demo::statisc(Mat& m) {
	int channels = m.channels();
	vector<Mat>cv;
	split(m, cv);
	for (int i = 0; i < channels; i++)
	{
		double minv, maxv;
		Point minLoc, maxLoc;
		minMaxLoc(m, &minv, &maxv, &minLoc, &maxLoc);//求像素最大最小值(单通道)
		cout << "min value:" << minv << "max value" << maxv << endl;
		
	}
	Mat avr, stddev;
	meanStdDev(m, avr, stddev);
	cout << "平均值:" << avr << "标准方差" << stddev << endl;
}
void demo::createshape(vector<Mat>& m) {
	Rect rect;//矩形定型
	rect.x = 50;//矩形起始点x
	rect.y = 50;//矩形起始点y
	rect.width = 100;//矩形宽
	rect.height = 100;//矩形高
	rectangle(m[0], rect, Scalar(0, 255, 0), 2, 8, 0);
	circle(m[0], Point(100, 100), 15, Scalar(255, 0, 0), 1, 0);//绘制圆
	line(m[0], Point(100, 100), Point(150, 150), Scalar(0, 0, 255), 2, 8, 0);
	Mat dst;
	addWeighted(m[0], 0.7, m[1], 0.3,0,dst);
	RotatedRect rrt;
	rrt.center = Point(75, 75);
	rrt.size = Size(150, 100);
	rrt.angle = 0;
	ellipse(dst, rrt, Scalar(100, 100, 100),1,8);
	imshow("绘制图形", dst);

}
void demo::writepixiv(Mat&m) {
	string filename,path;
	int flag;
	filename = "image.jpg";
	path = "";
	cin >> flag;
	cout << "1.默认位置和名字   2.自定义位置和名字" << endl;
	switch (flag) {
	case 1:break;
	case 2:
		cout << "请输入文件名" << endl;
		cin >> filename;
		cout << "请输入保存位置" << endl;
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
	fillPoly(poly, vp, Scalar(255, 0, 0),8, 0);//填充多边形
	polylines(poly, vp, true, Scalar(255, 255, 255), 2, 8, 0);//划线多边形
	imshow("多边形绘制", poly);
}
Point sp(-1, -1);
Point ep(-1, -1);
Mat temp;
void demo::mouse_drawing_demo(Mat& image) {
	namedWindow("鼠标绘制", WINDOW_AUTOSIZE);
	setMouseCallback("鼠标绘制", on_draw,(void*)(&image));
	imshow("鼠标绘制", image);
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
			imshow("roi区域", image(box));
			imshow("鼠标绘制", image);
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
				imshow("鼠标绘制", image);
			}
		}
	}
}