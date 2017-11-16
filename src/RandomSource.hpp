#ifndef RANDOMSOURCEHPP
#define RANDOMSOURCEHPP

using namespace std;
#include <vector>

 #ifdef __APPLE__
  #include <stdlib.h> //arc4random

 #elif __linux__
  #include <bsd/stdlib.h> // arc4random may require -lbsd compiler flag

 #elif _WIN32 
  #include <random> // Good ole rand with uniform_int_distribution
 #endif

namespace TreeKit {

 
/*
 For windows, we use a rand as our generator and 
uniform_int_distribution to distribute are random
numbers. We use this function to avoid modulo bias.
*/
 
 #ifdef _WIN32_
 
 /*
  Parameters: vector<int> V 
 */
  void GetRandomIntegers( vector<int> &V, size_t size, int upperBound ) {
   srand(time(NULL));
   uniform_int_distribution<> dist( 0, upperBound );

   for( size_t i = 0; i < size; i++ ) {
    V.push_back( dist( rand ) );
   }
  }

/*
 For Linux and MacOS we use arc4random_uniform. For some 
distro's such as Nvidia's L4T (Ubuntu) the libSDL needs
to be installed. When compiling pass the -lbsd flag.

 Example L4T: g++-7 RandomBase.hpp -c -lbsd -std=c++14
*/

 #elif defined(__APPLE__) || defined(__linux__)

  void GetRandomIntegers( vector<int> &V, size_t size, int upperBound ) {
   for( size_t i = 0; i < size; i++ ) {
    V.push_back( arc4random_uniform( upperBound ) );
   }
  }


 #endif


}


#endif
