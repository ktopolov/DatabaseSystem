# Multi-Language Project  
The name of this repo is misleading (based on what I initially was going to do). This is simply a repository where the amount of code will be lightweight, but I will be practicing using multiple development languages, including compiled vs. scripting languages. This is a multi-language development project to get used to Linux-based C++, Python development as well as Git.  
  
# Dependencies  
There are a few dependencies for this repo; one of which is OpenCV for C++. To install:
```
# Install minimal prerequisites (Ubuntu 18.04 as reference)
sudo apt update && sudo apt install -y cmake g++ wget unzip

# Download and unpack sources
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
unzip opencv.zip

# Create build directory
mkdir -p build && cd build

# Configure
cmake  ../opencv-4.x

# Build
cmake --build .
```

This repo is build around the Caffe framework. To install Caffe in Linux, use:  
```
sudo apt install caffe-cpu
```  
If you get an error saying `Unable to fetch some archives...` you may need to run `sudo apt-get update` prior to the previous line, and then run the previous line. See https://caffe.berkeleyvision.org/install_apt.html for full instructions. 
  
When completed, the following should be done:
*  [ ] Install OpenCV
*  [ ] Install Caffe
  
# Building  
The C++ portion of the project uses `CMake` to generate Makefile, and then `make` to build the project. It is useful to use the following aliases:  
  
```  
alias run_cmake='cmake -S <PATH_TO_REPO>/c++ -B <PATH_TO_REPO>/c++/build'
alias run_make='make -C <PATH_TO_REPO>/DatabaseSystem/c++/build'
```  
The first command generates the makefile in the `<PATH_TO_REPO>/c++/build` directory. The second navigates to that directory and buiolds the project.  
  
TODO: ADD MORE INFO
