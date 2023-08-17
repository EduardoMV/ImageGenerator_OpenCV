#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main() {

    Mat A(500, 500, CV_8U, Scalar(0));
    Mat B(500, 500, CV_8U, Scalar(0));
    Mat C(500, 500, CV_8U, Scalar(0));
    Mat D(500,500, CV_8U, Scalar(0));
    Mat E(500,500, CV_8U, Scalar(0));

    //MatB
    for (int j = 255; j < 499; j++){
        for (int i = 0; i < 255; i++) {
            B.at<uchar>(j,i) = (uchar)(255);
        }
    }
    for (int j = 0; j < 255; j++){
        for (int i = 255; i < 499; i++) {
            B.at<uchar>(j,i) = (uchar)(255);
        }
    }

    //MatC
    for (int j = 0; j < 499; j++){
        for (int i = 0; i < 499; i++) {
            if(i % 4 == 0){
                C.at<uchar>(j,i) = (uchar)(255);
            }
            else{
                C.at<uchar>(j,i) = (uchar)(0);
            }

        }
    }

    //MatD
    for (int j = 0; j < 499; j++){
        for (int i = 0; i < 499; i++) {
            if(j % 4 == 0){
                D.at<uchar>(j,i) = (uchar)(255);
            }
            else{
                D.at<uchar>(j,i) = (uchar)(0);
            }

        }
    }

    //MatE
    int squareSize = E.rows/5;
    for (int j = 0; j < E.rows; j++){
        for (int i = 0; i < E.cols; i++) {
            if(j / squareSize % 2 == 0){
                if(i / squareSize % 2 == 0){
                    E.at<uchar>(j, i) = uchar(0);
                }
                else{
                    E.at<uchar>(j, i) = uchar(255);
                }
            }
            else{
                if(i / squareSize % 2 == 1){
                    E.at<uchar>(j, i) = uchar(0);
                }
                else{
                    E.at<uchar>(j, i) = uchar(255);
                }
            }
        }
    }


    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", A);
    waitKey(0);
    imshow("PhotoFrame", B);
    waitKey(0);
    imshow("PhotoFrame", C);
    waitKey(0);
    imshow("PhotoFrame", D);
    waitKey(0);
    imshow("PhotoFrame", E);
    waitKey(0);
    return 0;
}
