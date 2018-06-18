This document contains video performance results for [Caffe SSD](https://github.com/weiliu89/caffe/tree/ssd).

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
In this test, SSD detection is run on the same video with different resolution on virtual machine and local machine. The total time taken for detection 
and detection speed in frames per second is output for each run. 

Video Link: https://www.youtube.com/watch?v=gBk6oT8YrJQ \
Downloader: QDownloader.net \
Video Length: 2 minutes 42 seconds \
Video Frame Rate: 30 fps

Note: the video is downloaded without sound.

1. Virtual Machine 
    1. Resolution: 1920 x 1080\
    work time = 155.825 seconds | Frame rate: 31.1953 fps
    2. Resolution: 1280 x 720\
    work time = 142.237 seconds | Frame rate: 34.1754 fps
    3. Resolution: 854 x 480\
    work time = 136.591 seconds | Frame rate: 35.588 fps
    4. Resolution: 426 x 240\
    work time = 131.317 seconds | Frame rate: 37.0172 fps
 
2. Local Machine 
    1. Resolution: 1920 x 1080\
    work time = 1189.22 seconds | Frame rate: 4.08756 fps
    2. Resolution: 1280 x 720\
    work time = 1180.41 seconds | Frame rate: 4.11807 fps
    3. Resolution: 854 x 480\
    work time = 1170.01 seconds | Frame rate: 4.15466 fps
    4. Resolution: 426 x 240\
    work time = 1173.08 seconds | Frame rate: 4.14379 fps
    
    
### Conclusion:
Virtual machine performs better, as expected compare to local machine. The detection time per frame
decreases with decrease in video resolution.

