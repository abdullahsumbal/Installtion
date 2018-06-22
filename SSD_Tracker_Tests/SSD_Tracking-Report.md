This document contains video performance results for [SSD_Tracker](https://github.com/abdullahsumbal/SSD_Tracker).

### Test Environments:
1. Local Machine
    1. Operating System: Ubuntu 16.04.4 LTS
    2. OpenCV version: 3.3.1
    3. GPU: GeForce GTX 645/PCIe/SSE2
    4. CPU: Intel® Core™ i7-4770 CPU @ 3.40GHz × 8 
    5. CUDA version: 8.0 
    6. cuDNN version: 6.0 

1. Virtual Machine
    1. Operating System: Ubuntu 16.04.4 LTS 
    2. OpenCV version: 3.4.1
    3. GPU: NVIDIA M60 TESLA
    4. CPU: Intel(R) Xeon(R) CPU E5-2690 v3 @ 2.60GHz 
    5. CUDA version: 8.0 
    6. cuDNN version: 6.0 
    
### Test 1:
In this test, SSD detection and tracking is run on the same video with different resolution on virtual machine and local machine. 
The Total time is recoded for each video which includes 
1. ssd detection 
2. tracking
3. drawing on boxes and tracking lines on the frames 
4. storing output video on disk.
 
Frame rate is calculated by dividing Total time by number of frames.  

Video Link: https://www.youtube.com/watch?v=gBk6oT8YrJQ \
Downloader: QDownloader.net \
Video Length: 13 seconds (first 400 frames)
Video Frame Rate: 30 fps \
SSD Detection: [models_VGGNet_VOC0712_SSD_300x300](https://drive.google.com/file/d/0BzKzrI_SkD1_WVVTSmQxU0dVRzA/view)

Note: the video is downloaded without sound.

1. Virtual Machine 
    1. Resolution: 1920 x 1080\
    Total time = 20.2323 seconds | Frame rate: 19.8198 fps
    2. Resolution: 1280 x 720\
    Total time = 15.4806 seconds | Frame rate: 25.9034 fps
    3. Resolution: 854 x 480\
    Total time = 13.2859 seconds | Frame rate: 30.1824 fps
    4. Resolution: 426 x 240\
    Total time = 11.8224 seconds | Frame rate: 33.9188 fps
 
2. Local Machine 
    1. Resolution: 1920 x 1080\
    Total time = 105.551 seconds | Frame rate: 3.79913 fps
    2. Resolution: 1280 x 720\
    Total time = 102.063 seconds | Frame rate: 3.92895 fps
    3. Resolution: 854 x 480\
    Total time = 98.7727 seconds | Frame rate: 4.05983 fps
    4. Resolution: 426 x 240\
    Total time = 98.1054 seconds| Frame rate: 4.08744 fps
    
    
#### Conclusion:
Virtual machine performs better, as expected compare to local machine. The detection time per frame
decreases with decrease in video resolution. There is a more drastic decrease in frame rate when only detection is performed.

Please also refer to the following test(s)
1.  [Caffe test](/Caffe_Proformance_Test/Local_Vs_Virtual_speed.md)


### Test 2:
In this test, SSD detection and tracking is run on the same video with different resolution on virtual machine. 
The Total time is recoded for each video which includes 
1. ssd detection 
2. tracking
3. drawing on boxes and tracking lines on the frames 
4. storing output video on disk.

Frame rate is calculated by dividing Total time by number of frames.  

Video Link: https://www.youtube.com/watch?v=gBk6oT8YrJQ \
Downloader: QDownloader.net \
Video Length: 13 seconds (first 400 frames)
Video Frame Rate: 30 fps \
SSD Detection: [models_VGGNet_VOC0712_SSD_300x300](https://drive.google.com/file/d/0BzKzrI_SkD1_WVVTSmQxU0dVRzA/view)

Note: the video is downloaded without sound.

1. Virtual Machine 
    1. Resolution: 1920 x 1080\
        Total time = 20.3877 seconds | Frame rate: 19.6688 fps\
        Total Detection time = 11.5326 seconds\
        Total Tracking time = 2.86798 seconds\
        Total Drawing time = 0.149267 seconds\
        Total Storing time = 4.10904 seconds
    2. Resolution: 1280 x 720\
        Total time = 15.5311 seconds | Frame rate: 25.8192 fps \
        Total Detection time = 11.4366 seconds \
        Total Tracking time = 1.04571 seconds\
        Total Drawing time = 0.115335 seconds\
        Total Storing time = 2.13758 seconds
    3. Resolution: 854 x 480\
        Total time = 13.4501 seconds | Frame rate: 29.8138 fps
        Total Detection time = 11.3153 seconds\
        Total Tracking time = 0.438523 seconds\
        Total Drawing time = 0.102125 seconds\
        Total Storing time = 1.15259 seconds

    4. Resolution: 426 x 240\
        Total time = 11.901 seconds | Frame rate: 33.6946 fps \
        Total Detection time = 11.1076 seconds \
        Total Tracking time = 0.114087 seconds \
        Total Drawing time = 0.0736228 seconds \
        Total Storing time = 0.431988 seconds
        
#### Conclusion:
Detection, tracking, drawing and storing time increases with increase in resolution. Storing time seems to increase the 
most.

Please also refer to the following test(s)
1.  [Caffe test](/Caffe_Proformance_Test/Local_Vs_Virtual_speed.md)