


1. https://github.com/BVLC/caffe/issues/5810
2. https://github.com/NVIDIA/DIGITS/issues/156
3. https://github.com/BVLC/caffe/issues/2347


ls -l libboost_python*
sudo rm -rf libboost_python.so
sudo ln -s libboost_python-py35.so libboost_python.so

Notes on caffe.
1. https://medium.com/@shiyan/caffe-c-helloworld-example-with-memorydata-input-20c692a82a22

###CMAKE
sudo cmake -DCUDNN_LIBRARY=/usr/local/cuda/lib64/libcudnn.so  -DCMAKE_BUILD_TYPE=Relase .
make -j 12 && make install
https://github.com/BVLC/caffe/pull/1667

##

./build/examples/ssd/ssd_detect.bin models/VGGNet/VOC0712/SSD_300x300/deploy.prototxt models/VGGNet/VOC0712/SSD_300x300/VGG_VOC0712_SSD_300x300_iter_120000.caffemodel examples/images/list.txt


./test_caffe /home/sumbal/projects/caffe/models/VGGNet/VOC0712/SSD_300x300/deploy.prototxt /home/sumbal/projects/caffe/models/VGGNet/VOC0712/SSD_300x300/VGG_VOC0712_SSD_300x300_iter_120000.caffemodel /home/sumbal/projects/caffe/examples/videos/list.txt
