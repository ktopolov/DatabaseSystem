# DatabaseSystem
Multi-language development project to get used to Linux-based C++, Python development as well as Git  
  
# Dependencies  
This repo is build around the Caffe framework. To install Caffe in Linux, use:  
```
sudo apt install caffe-cpu
```  
If you get an error saying `Unable to fetch some archives...` you may need to run `sudo apt-get update` prior to the previous line, and then run the previous line. See https://caffe.berkeleyvision.org/install_apt.html for full instructions. 
  
# Building  
The C++ portion of the project uses `CMake` to generate Makefile, and then `make` to build the project. It is useful to use the following aliases:  
  
```  
alias run_cmake='cmake -S <PATH_TO_REPO>/c++ -B <PATH_TO_REPO>/c++/build'
alias run_make='make -C <PATH_TO_REPO>/DatabaseSystem/c++/build'
```  
The first command generates the makefile in the `<PATH_TO_REPO>/c++/build` directory. The second navigates to that directory and buiolds the project.  
  
TODO: ADD MORE INFO
