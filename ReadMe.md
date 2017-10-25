
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

### Unit Testing

If you want to run the unit test, you'll also need to clone and build the *GoogleTest* source. I highly recommend building the code as library. I created a directory named *library* and built the source to this folder.

First clone the *GoogleTest* repository.
```
git clone https://github.com/google/googletest.git
```

Go to the directory and make a directory called (wait for it) *library.* Go to this directory.

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
g++-7 -isystem <PathToGoogleTest>/googletest/googletest/include -pthread *.cpp <PathToGoogleTest>/googletest/googletest/library/libgtest.a -o testApp
```

Run the test.
```
./testApp
```
