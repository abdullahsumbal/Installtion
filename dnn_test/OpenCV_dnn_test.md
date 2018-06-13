This document shows the performance of the dnn using CPU and GPU.\
We look at two models torch and caffe in our example.  
Sample code in for both model are taken from opencv/sample/dnn directory. 


### My Test Environment: 
1. Operating System: Linux
2. OpenCV version: 3.3.1 [(Follow Steps here to install)](/OpenCV_installation_steps.md)
3. GPU: NVIDIA GTX 645
4. CPU: Intel® Core™ i7-4770 CPU @ 3.40GHz × 8



### Step 1: Set Environment Variable
We have to tell which device to use for GPU. 
```
# This command will temporarily set OPENCV_OPENCL_DEVICE to use nvidia gpu for the current session.  
export OPENCV_OPENCL_DEVICE=NVIDIA:GPU:
# If you have a different GPU set it to the following or google hwo to set it up for your GPU,
export OPENCV_OPENCL_DEVICE=:GPU:
```
### Step 2: Download models
1. For Torch download from [here](https://www.dropbox.com/sh/dywzk3gyb12hpe5/AAD5YkUa8XgMpHs2gCRgmCVCa).
2. For Caffe download from [here](https://github.com/weiliu89/caffe/tree/ssd).

# Step 3: Add model location to the files.
1.Edit the caffe_dnn_test.cpp file in SSD_CAFFE directory
```
# I placed my models in the same directory as SSD_CAFEE
        = "{ help           | false | print usage         }"
          "{ proto          |deploy.prototxt       | model configuration }"
          "{ model          |VGG_VOC0712Plus_SSD_300x300_ft_iter_160000.caffemodel       | model weights       }"
          "{ image          |people.jpg       | image for detection }"
          "{ min_confidence | 0.5   | min confidence      }";

```
2.Edit the torch_dnn_test.cpp file in TORCH directory
``` 
        # I placed my models in the same directory as TORCH
        "{help h    || Sample app for loading ENet Torch model. "
                       "The model and class names list can be downloaded here: "
                       "https://www.dropbox.com/sh/dywzk3gyb12hpe5/AAD5YkUa8XgMpHs2gCRgmCVCa }"
        "{model m   |model-best.net | path to Torch .net model file (model_best.net) }"
        "{image i   |people.jpg | path to image file }"
        "{c_names c |categories.txt | path to file with classnames for channels (optional, categories.txt) }"
        "{result r  || path to save output blob (optional, binary format, NCHW order) }"
        "{show s    || whether to show all output channels or not}"
        "{o_blob    || output blob's name. If empty, last blob's name in net is used}"
```

### Step 4. Compile file for CPU/GPU usage 
Go the SSD_CAFFE directory.
```
cd SSD_CAFEE
```
Edit line in caffe_dnn_test.cpp. Set setPreferableTarget to 0 for CPU and 1 for GPU
```
net.setPreferableTarget(0);
```
Compile file
``` 
g++ -std=c++11 opencl_test.cpp `pkg-config --libs --cflags opencv`
```

### Step 5: Run test
```
./a.out
```

### Step 6 & 7:
Same steps for the Torch.


### Conclusion
The purpose of the test is compare the CPU and GPU time of the models but not against with other.
Time difference in time between models can be due to different implementations of the test files. 
1. Caffe test results
    1. GPU: 0.176261 ms
    2. CPU: 0.176978 ms 
    
    The results are almost the same. At this point we were not sure if the GPU was being utilised
      
2. Torch test results
    1. GPU: 370.12 ms
    2. CPU: 288.752 ms
    
    The time gets worse on GPU. 
    
These results actually matches to dnn Efficiency results posted on OpenCV [wiki page](https://github.com/opencv/opencv/wiki/DNN-Efficiency#cpu).  