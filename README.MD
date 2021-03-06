# Yet Another Telegram Bot CPP API


* Many Features are currently just implemented and might change heavily, feel free to use or wait till first "usefull" version
* First "useful" version will have something like 0.1.* and not 0.0.*
* Development Alpha is Currently 0.0.1 ( the latest release will currently always have this tag)
* For Installation or Compile Instructions, take a look at Install.MD


## About 
Small Telegram Bot Api which sure misses some functionality, but if you think one should be implemented earlier, feel free to contact me.

For More Information Checkout the [Documentation](https://yatbcpp.norbert-ruehl.de/doc) or [Bot Api](https://core.telegram.org/bots/api)


## Features 
* Allows to register on Message or on Command or on InlineQuery
* sendMessage is possible
* sendPhoto is possible , use telegramMethodMultipart for sending a local file
* sendAudio is possible , use telegramMethodMultipart for sending a local file

## Requirements 
* [cmake](https://cmake.org/) 
* [jsoncpp](https://github.com/open-source-parsers/jsoncpp)
* [CURL](https://github.com/curl/curl)
* threading ( multi threading was touched first, pure single thread might come sooner or later)
* c++17 or experimental features at least , e.g. gcc7
    * In general use CMAKE_COMPILER / CMAKE_CXX_COMPILER to set an appropriate compiler
        * e.g. Linux supply -DCMAKE_C_COMPILER=/usr/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/bin/g++-7
        * e.g. MacOS supply -DCMAKE_C_COMPILER=/usr/local/bin/gcc-7 -DCMAKE_CXX_COMPILER=/usr/local/bin/g++-7
* Support for optional or at least experimental optional        

## Compile Instructions
* mkdir -p build
* cd build
* cmake ..
* make
* sudo make install

## apt-get Instructions
* [packages.norbert-ruehl.de](https://packages.norbert-ruehl.de)
* [norbekaiser.github.io/packages](https://norbekaiser.github.io/packages/)

## Homebrew Instructions
* brew tap [norbekaiser/yatbcpp](https://github.com/norbekaiser/homebrew-yatbcpp)
* There is an Issue with optional on sierra / high sierra , please consider compiling with a different compiler  ```brew install yatbcpp --cc=gcc-7```

## vcpkg Instructions
* coming soon?

## Usage Instructions (find_package)
* Hello-User Example [Github](https://github.com/norbekaiser/yatbcpp-example-hello-user) [yatbcpp.norbert-ruehl.de](https://yatbcpp.norbert-ruehl.de/src/?p=yatbcpp-example-hello-user;a=tree)
    * Small Example Which requires installed yatbcpp
    * Build is also possible with external_project ( dedicated example will follow soon)

## Mirrors and other Repos
* [github.com/norbekaiser/yatbcpp](https://github.com/norbekaiser/yatbcpp.git) [yatbcpp.norbert-ruehl.de](https://yatbcpp.norbert-ruehl.de/src/?p=yatbcpp;a=tree)
    * This Repo will contain the stable releases as well as the current dev commits
    * [![Build Status](https://travis-ci.org/norbekaiser/yatbcpp.svg?branch=master)](https://travis-ci.org/norbekaiser/yatbcpp)
* [github.com/norbekaiser/homebrew-yatbcpp](https://github.com/norbekaiser/homebrew-yatbcpp.git)
    * Contains the Formula for source build using homebrew
* [github.com/norbekaiser/macos-yatbcpp](https://github.com/norbekaiser/yatbcpp-macos) [yatbcpp.norbert-ruehl.de](https://yatbcpp.norbert-ruehl.de/src/?p=yatbcpp-macos;a=tree)
    * Use this Repo to checkout for mac
    * Main difference: json/json.h instead of jsoncpp/json/json.h header
    * [![Build Status](https://travis-ci.org/norbekaiser/yatbcpp-macos.svg?branch=master)](https://travis-ci.org/norbekaiser/yatbcpp-macos)
* Feel free to open an issue on one of these repos, however development will be done on a private [gitlab](https://gitlab.norbert-ruehl.de/yatbcpp/yatbcpp) instance, it might take some time till an update is pushed to the mirroring repos
* If you wish for another mirror on another plattform just contact me
* [packages.norbert-ruehl.de](https://packages.norbert-ruehl.de)
* [norbekaiser.github.io/packages](https://norbekaiser.github.io/packages/)

## Documentation
* Doxygen Documentation is available [yatbcpp-doc](https://yatbcpp.norbert-ruehl.de/doc)
