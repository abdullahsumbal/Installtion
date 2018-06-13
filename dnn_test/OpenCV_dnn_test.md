This document shows how to test GPU performance and GPU performance using OpenCL..


### My Test Environment: 
1. Operating System: Linux
2. OpenCV version: 3.3.1 [(Follow Steps here to install)](/OpenCV_installation_steps.md)
3. GPU: NVIDIA GTX 645
4. Video name : atrium.avi \
    Video duration: 14 seconds\
    Video Resolution: 640 x 360\
    Video Frame rate: 30 fps



### Step 1: Set Environment Variable
We have to tell which device to use for GPU. 
```
# This command will temporarily set OPENCV_OPENCL_DEVICE to use nvidia gpu for the current session.  
export OPENCV_OPENCL_DEVICE=NVIDIA:GPU:
# If you have a different GPU set it to the following or google hwo to set it up for your GPU,
export OPENCV_OPENCL_DEVICE=:GPU:
```

### Step 2. Compile file
The test file is in the OpenCL folder of this repo.
```
cd OpenCL
g++ -std=c++11 opencl_test.cpp `pkg-config --libs --cflags opencv`
```
### Step 3: Run test

#### Step 3.1 with GPU 
```
./a.out 1
```

#### Step 3.2 with CPU 
```
./a.out 0
```

### Step 4: Look at the results
1. CPU : FINAL AVERAGE FRAME PER SECOND: 229.231
2. GPU : FINAL AVERAGE FRAME PER SECOND: 437.971

### Extra Note:
1. There is already a video file in the OpenCL folder along with the test file.
2. The video output is turned off. It can be turned on by uncommenting line no. 69 in opencl_test.cpp
    ``` 
    //cv::imshow("Sobel blurred Frame", blurredSobel);
    ```
3. If you are getting the same results. Please make sure OpenCl is installed by checking the first line 
that is printed on the screen by the running the test file.
4. If the project is not compiling, you might have a different version of OpenCV.
5. If the getting the same speed, play around with the environment variable. [Read more](http://answers.opencv.org/question/59115/opencv-30-beta-and-opencl-setdevice/). 
6. This example is very much inspired from [here](http://answers.opencv.org/question/58331/opencv-300-and-opencl-benchmark-sobel-edge-detection/).

