#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>
using namespace std;
using namespace cv;
class solvtion {
public:
    void gray(Mat&);
};
void solvtion::gray(Mat& test) {   
    Mat M1=test.clone();
    cvtColor(M1, M1, CV_BGR2GRAY);
    namedWindow("GRAY", WINDOW_FREERATIO);
    imshow("GRAY", M1);
    waitKey(0);
}
int main()
{
    std::string path = "G:\\test1.jpg";
    Mat img = imread(path);
    if (img.empty()) {
        cout << "cannot open this file" << endl;
        return -1;
    }
    namedWindow("TEST", WINDOW_FREERATIO);
    imshow("TEST", img);
    solvtion solve;
    solve.gray(img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}