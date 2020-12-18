# SYSZUX-FACE
face detect based on opencv &amp; libdeepvac  

# 简介
本项目实现了人脸检测C++ API，支持在Linux上编译和运行。
```c++
//weights_path is face detect weights path.
SyszuxFace face_detect(weights_path);

//mat is cv::Mat type
//detect_out is std::vector<cv::Mat> type
auto detect_out = face_detect.process(mat);
```

# 从源码编译
我们使用Docker来作为构建环境，包括如下步骤：
- 准备编译环境；
- 克隆该仓库；
- 配置和编译;
- 运行。

#### 准备编译环境
- 启动容器
```bash
docker run -it --name gemfield -h gemfield ubuntu:20.04 bash
```
- 安装依赖包
```bash
apt update
apt install cmake g++ git libopencv-dev
```

- 下载libdeepvac预编译库
```bash
wget https://github.com/DeepVAC/libdeepvac/releases/download/1.6.0/libdeepvac.tar.gz
tar zxvf libdeepvac.tar.gz
```
#### 克隆该仓库
```bash
git clone https://github.com/CivilNet/SYSZUX-FACE
```
#### 配置和编译
```bash
cd SYSZUX-FACE
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=<libdeepvac_dir> ..
make
```

#### 运行
```bash
#in build dir
bin/syszux_face_detect ../deepvac_zoo/face_retina.deepvac /home/gemfield/test1.jpg
```
程序输出检测到的人脸数量，以及将检测到的人脸裁切写入当前目录。

