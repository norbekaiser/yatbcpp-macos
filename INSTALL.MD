# Yet Another Telegram Bot C++ Library
## Install Instructions
 
### Apt (Debian / Ubuntu) 
I do provide prebuilt deb packages

#### Adding the Key to apt
```
wget -q -O - https://packages.norbert-ruehl.de/conf/apt.gpg.key | sudo apt-key add -
```

#### Adding the Repo Location to the Source list
For the following distributions packages are built , currently for amd64 only
In case you wish for another, just open an issue or email me

##### Debian 9 Stretch 
```
sudo sh -c 'echo deb https://packages.norbert-ruehl.de/debian stretch main > /etc/apt/sources.list.d/packages.norbert-ruehl.de.list'
```

##### Ubuntu 16.04 Xenial
```
sudo sh -c 'echo deb https://packages.norbert-ruehl.de/ubuntu xenial main > /etc/apt/sources.list.d/packages.norbert-ruehl.de.list'
```

##### Ubuntu 18.04 Bionic
```
sudo sh -c 'echo deb https://packages.norbert-ruehl.de/ubuntu xenial main > /etc/apt/sources.list.d/packages.norbert-ruehl.de.list'
```

#### Installing the Library 
```
sudo apt-get update
```

##### Library Only
```
sudo apt-get install libyatbcpp
```

##### Library and Includes
```
sudo apt-get install libyatbcpp-dev
```


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
git clone REPO_URL
cd REPO_URL
mkdir -p build
cd build
cmake .. -DCMAKE_C_COMPILER=/usr/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/bin/g++-7
make
sudo make install
```

### Compile From Source Using GCC 7 on (Macos) 
```
git clone REPO_URL
cd https://github.com/norbekaiser/yatbcpp-macos.git
mkdir -p build
cd build
cmake .. -DCMAKE_C_COMPILER=/usr/local/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-7
make
sudo make install
```
