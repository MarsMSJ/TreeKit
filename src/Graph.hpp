#ifndef _GRAPHTREE_HPP
#define _GRAPHTREE_HPP

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

namespace GraphKit {

	/*
	 Simple node class with a vector to store adjacent nodes
	*/
	template<class V>
	class GraphNode{
	 public: 
	  V Value;
          vector<GraphNode *> AdjVector;	 

	//Constructor, for convenience
	  GraphNode( V value ) {
	   Value = value; 
	  }
	 
	};//class end

} //namespace Graph Kit end
#endif
