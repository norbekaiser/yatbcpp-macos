# Yet Another Telegram Bot C++ Library
## Install Instructions
 
### Apt (Debian / Ubuntu) 
I do provide prebuilt deb packages for debian, raspbian and ubuntu
Take a look at 
* [packages.norbert-ruehl.de](https://packages.norbert-ruehl.de)
* [norbekaiser.github.io/packages](https://norbekaiser.github.io/packages/)

### Homebrew (Macos)
```brew
brew tap norbekaiser/yatbcpp
brew install yatbcpp 
```
There is a known issue with the xcode compiler and some features, consider using a different compiler
```
brew install yatbcpp --cc=gcc-7
```
 
### Compile From Source
Normaly this would be enough, however some features might be not as they are C++17 Features
```
mkdir -p build
cd build
cmake ..
make
sudo make install
```
 
### Compile From Source Using GCC 7 (Debian / Ubuntu)

* [cmake](https://cmake.org/) 
* [jsoncpp](https://github.com/open-source-parsers/jsoncpp)
* [CURL](https://github.com/curl/curl)

Any of the libcurl Packages should be sufficient
```
sudo apt-get install git cmake build-essential libjsoncpp-dev libcurl-dev
git clone REPO_URL yatbcpp
cd yatbcpp
mkdir -p build
cd build
cmake .. -DCMAKE_C_COMPILER=/usr/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/bin/g++-7
make
sudo make install
```

### Compile From Source Using GCC 7 on (Macos) 
```
git clone REPO_URL yatbcpp
cd yatbcpp
mkdir -p build
cd build
cmake .. -DCMAKE_C_COMPILER=/usr/local/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-7
make
sudo make install
```
