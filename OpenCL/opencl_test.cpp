#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/ocl.hpp>


int main(int argc, char** argv)
{
    std::cout << "Have OpenCL ?: " << cv::ocl::haveOpenCL() << std::endl;

    bool use_opencl = false;
    if(argc > 1) {
        use_opencl = std::string(argv[1]) == "1";
    }

    std::cout << "use_opencl=" << use_opencl << std::endl;

/*  SWITCH OPENCL ON/OFF IN LINE BELLOW */
    cv::ocl::setUseOpenCL(use_opencl);
/*                                      */
    int nBlurs = 50;

    cv::VideoCapture cam;

    if (!cam.open("atrium.avi")) {
        std::cout << "Problem connecting to cam " << std::endl;
        return -1;
    }
    else {
        std::cout << "Successfuly connected to camera " << std::endl;
    }

    cv::UMat frame;
    cv::UMat frameGray;
    cv::UMat frameSobelx;
    cv::UMat frameSobely;

    cv::UMat frameSobel;
    cv::UMat blurredSobel;

    char c;
    double total_time = 0.0;
    int cpt = 0;
    while(c != 27)
    {
        cam >> frame;

        if(frame.empty()){
            break;
        }

        double t = (double) cv::getTickCount();
        cv::cvtColor(frame, frameGray, cv::COLOR_BGR2GRAY);

        cv::Sobel(frameGray, frameSobelx, frameGray.depth(), 1, 0, 3);
        cv::Sobel(frameGray, frameSobely, frameGray.depth(), 0, 1, 3);

        cv::bitwise_or(frameSobelx, frameSobely, frameSobel);

        for (int n = 0; n < nBlurs; n++) {
            cv::blur(frameSobel, blurredSobel, cv::Size(3,3));
        }

        t = ((double) cv::getTickCount() - t) / cv::getTickFrequency();
        total_time += t;
        cpt++;
        std::cout << "Times passed in seconds: " << t << " ; FPS: " << (1/t) << " ; average FPS=" << (cpt/total_time) << std::endl;

        //cv::imshow("Sobel blurred Frame", blurredSobel);

        c = cv::waitKey(30);
    }
    std::cout << "FINAL AVERAGE FRAME PER SECOND: " << (cpt/total_time) << std::endl;
    return 0;
}
