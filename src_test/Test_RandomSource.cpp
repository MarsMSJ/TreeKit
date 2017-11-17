#include <string>
#include <stack>
#include "gtest/gtest.h"
#include "../src/RandomSource.hpp"
#include <iostream>

namespace {
  TEST( Test_RandomBase, RandomIntSet_Empty ){
    size_t size = 0;
    int upperBound = 1000;

    //should return an empty vector V
    vector<int> V;
    TreeKit::GetRandomIntegers( V, size, upperBound );
    ASSERT_TRUE( V.empty() );
  }

  TEST( Test_RandomBase, RandomIntSet_Small ){
    size_t size = 10;
    int upperBound = 1000;
    vector<int> V;
    TreeKit::GetRandomIntegers( V, size, upperBound );

    //Test we have the right size
    ASSERT_TRUE( !V.empty() && V.size() == size );
    
    //Test numbers generated confirm to upper bound
    bool result = true;
    for( auto i : V ) {
     if( i > upperBound ) {
       result = false;
       break;
     }
    }
    ASSERT_TRUE( result );
  }

  TEST( Test_RandomBase, RandomIntSet_Medium ){
    size_t size = 1000;
    int upperBound = 1000;
    vector<int> V;
    TreeKit::GetRandomIntegers( V, size, upperBound );

    //Test we have the right size
    ASSERT_TRUE( !V.empty() && V.size() == size );
    
    //Test numbers generated confirm to upper bound
    bool result = true;
    for( auto i : V ) {
     if( i > upperBound ) {
       result = false;
       break;
     }
    }
    ASSERT_TRUE( result );
  }

  TEST( Test_RandomBase, RandomIntSet_Large ) {
    size_t size = 1000000;
    int upperBound = 1000;
    vector<int> V;
    TreeKit::GetRandomIntegers( V, size, upperBound );

    //Test we have the right size
    ASSERT_TRUE( !V.empty() && V.size() == size );
    
    //Test numbers generated confirm to upper bound
    bool result = true;
    for( auto i : V ) {
     if( i > upperBound ) {
       result = false;
       break;
     }
    }
    ASSERT_TRUE( result );
  }

  TEST( Test_RandomBase, RandomIntSet_ZeroBound ){
    size_t size = 1000;
    int upperBound = 0;
    vector<int> V;
    TreeKit::GetRandomIntegers( V, size, upperBound );

    //Test we have the right size
    ASSERT_TRUE( !V.empty() && V.size() == size );
    
    //Test numbers generated are stream of 0's 
    bool result = true;
    for( auto i : V ) {
     if( i > upperBound ) {
       result = false;
       break;
     }
    }
    ASSERT_TRUE( result );
  }
}
