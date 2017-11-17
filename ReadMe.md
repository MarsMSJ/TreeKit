
# Tree Kit
Simple code kit to include into your c++ programs so you can jump straight into your algorithms. Can generate binary trees and binary search trees randomly.

## Getting Started

In order to build and run this code you'll need a *C++ compiler compatible with C++14.* To run the test you'll need clone and build *GoogleTest* Github project on your platform.

### Prerequisites

* [GNU Compiler](https://gcc.gnu.org)
  * I used GCC 7.2.0 in both *MacOS High Sierra* and *L4T*.
* [Homebrew](https://brew.sh)
  * *Optional* but I highly recommend *Homebrew* to install GCC if you're using *MacOS.* It's awesome!
* [Google Test](https://github.com/google/googletest)
  * *Optional* if you would like to run the unit tests.

### Platforms

* MacOS High Sierra
* MacOS Sierra
* Linux4Tegra (L4T) 
  * L4T aka Ubuntu 14.04 LTS. Custom NVidia Ubuntu distro for Jetson embedded hardware.
  * The *-std=c++14* flag is required.


### Random Integer Generation

If you simply want to use the *random number generator* portion simply pass an *lvalue reference* of vector<int> type to GetRandomIntegers along with a size and upper bound parameter. For random integers we use arc4random_uniform on Mac/Ubuntu and on Windows we use std::rand and uniform_int_distribution (to avoid modulo bias.) 

```
/*
	We want 10 integers from 0 to 1000 generated and stored in our std::vector<int> V.
*/
std::vector<int> V;
TreeKit::GetRandomIntegers( V, 10, 1000)
```

### Unit Testing

If you want to run the unit test, you'll also need to clone and build the *GoogleTest* source. There is a *Test_main.cpp* provided. If you're not familiar with running these test I have an easy way of doing this described below.


 

First clone the *GoogleTest* repository to the same folder containing the TreeGraphKit. See image below.

```
git clone https://github.com/google/googletest.git
```

How the folder layout should look like. 

![Folder Layout](https://github.com/MarsMSJ/TreeKit/raw/Images/images/FolderArrangement.png )


Go to the *googletest* directory and make a directory called (wait for it) *library.* Go to this directory.

```
cd googletest/googletest
mkdir library
cd library
```

Now build the library. I'm using GCC 7.2.0.

```
g++-7 -isystem ../include -I.. -pthread -c ../src/gtest-all.cc
ar -rv libgtest.a gtest-all.o
```

Now go src_test directory located in the TreeGraphKit folder and build the test.
```
g++-7 -isystem ~/Dev/CPP/Opensource/googletest/googletest/include -pthread *.cpp ~/Dev/CPP/OpenSource/googletest/googletest/library/libgtest.a -o testApp
```

Run the test.
```
./testApp
```

I have also included a script that does the above if you follow my folder layout. Just remember to chmod the script before running the script.
```
chmod +x script_compileTest.sh 
./script_compileTest.sh
```
