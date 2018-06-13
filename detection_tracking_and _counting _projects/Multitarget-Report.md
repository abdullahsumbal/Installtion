This document contains implementation details and analysis of the Multitarget-tracker Project. The original project 
can be found [here](https://github.com/Smorodov/Multitarget-tracker).

### Project Repositories
1. Original:
[https://github.com/Smorodov/Multitarget-tracker](https://github.com/Smorodov/Multitarget-tracker)
2. My clone: [https://github.com/abdullahsumbal/SSD_OBJECT_COUNTER](https://github.com/abdullahsumbal/SSD_OBJECT_COUNTER)

### My Development Environment: 
1. Operating System: Linux
2. OpenCV version: 3.3.1
3. GPU: NVIDIA GTX 645
4. CPU: Intel® Core™ i7-4770 CPU @ 3.40GHz × 8

### Installation
Follow the [steps](https://github.com/abdullahsumbal/SSD_OBJECT_COUNTER) to install the project.

### Implementation
1. The original project follows the following pipeline

    Input video --> Detection --> Tracking --> Output video \

2. I changed the project to the follwowing pipeline
    
    Input video --> Detection --> Tracking --> counting --> Output video 

3. Detection part uses SDD_MobileNet model.
4. Tracking part uses Kalman and hungarian algorithm.
5. Counting uses line and mesh approach.
6. The project utilizes GPU opencl library api. 

### Final Thoughts

This is a very useful project that uses Opencv very efficiently. The bottle neck part is the detection.
Even with the GPU, the performance did not improve. [Here](https://docs.google.com/document/d/1huiasSPZzirTSII2DWap6VNKX990WPU8EsVr0v4vqak/edit?usp=sharing)
 are some speed test conducted on the project. More opencv dnn results can be found [here](/dnn_test/OpenCV_dnn_test.md). In the end we decided to use this project and replace the opencv dnn (which is used for detection)
 with caffe. AS caffe uses CUDA, we expect to see performance improvements in detection time. 

