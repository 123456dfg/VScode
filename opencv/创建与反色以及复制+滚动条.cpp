#include"func.h"
int main() {
	demo project;
	string path1;
	path1 = "G:\\test1.jpg";
	Mat read=imread(path1, 1);
	namedWindow("输入窗口", WINDOW_FREERATIO);
	imshow("输入窗口", read);
	vector<Mat>mv;
	mv = project.create_rectangle();
	//project.bitwise_and(mv);
	project.mouse_drawing_demo(read);
	
	//Mat m1 = Mat::zeros(Size(1080, 720), CV_8UC3);//（宽，高）//创建图像
	//m1 = Scalar(228, 135, 245);//图像赋值
	//namedWindow("输入图像", WINDOW_FREERATIO);
	//imshow("输入图像", m1);
	//system("cls");
	//while (1) {
	//char input;
	//input = waitKey(0);
	//	switch (input) {
	//	case '1':project.contrayp(m1); system("cls"); break;
	//	case '2':project.trackingbar(m1); system("cls"); break;
	//	case '3':cout << "width： " << m1.cols << "  length： " << m1.rows << "  cannels： " << m1.channels() << endl; break;
	//	case '4':return 0;//退出
	//	}
	//}
	waitKey(0);
	return 0;
}