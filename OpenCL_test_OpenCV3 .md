This document shows how to test GPU performance and GPU performance using OpenCL.


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