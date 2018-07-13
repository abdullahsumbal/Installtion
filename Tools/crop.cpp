#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/ocl.hpp>


int main(int argc, char** argv)
{

    // Set up input
    cv::VideoCapture cap(argv[1]);
    if (!cap.isOpened()) {
        std::cout << "Failed to open video: " ;
    }
    cv::Mat frame;
    int frameCount = 0;

    // video output
    cv::VideoWriter writer;


    char c;
    while(true)
        {
            bool success = cap.read(frame);
            if (!success) {
                break;
            }

            cv::Mat copyFrame(frame, cv::Rect(960, 1100, 600, 400));
            //copyFrame.copyTo(frame);
            frame = copyFrame;


            if (atoi(argv[3]) == 1){
            cv::line( frame, cv::Point( 290, 0 ), cv::Point( 290, 600), cv::Scalar( 120, 220, 0 ),  2, 8 );
            cv::line( frame, cv::Point( 310, 0 ), cv::Point( 310, 600), cv::Scalar( 120, 220, 0 ),  2, 8 );
            }



            if (!writer.isOpened())
            {
                writer.open(argv[2], cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, frame.size(), true);
            }

            if (writer.isOpened())
            {
                writer << frame;
            }
        }
        if (cap.isOpened()) {
            cap.release();
        }
}