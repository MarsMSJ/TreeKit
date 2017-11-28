#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

namespace TreeKit {
 namespace BinaryTreeKit {

	/*
	 Simple node class with left and right child links. Includes
	an optional count field. The count field is useful for repr-
	esenting duplicate values without storing them. Another use-
	ful function is to store the count of nodes below a given
	node.
	*/
	template<class V>
	class BinaryNode{
	 public: 
	  V Value;
	  BinaryNode<V> *Left;
	  BinaryNode<V> *Right;
	  size_t Count; // Optional

	//Constructor, for convenience
	  BinaryNode( V value ) {
	   Value = value; 
           Count = 1;
	   Left = Right = nullptr;
	  }
	 
	};//class end

	/*
	 Insert's into the next available position in the tree. If a nullptr
	pointer is passed for the root, the function returns the new root. 
	Otherwise, given a root, the function returns the node inserted. Use-
	ful for generating random binary trees to "fix" by balancing or heapify
	algorithms.

 	Time Complexity: O(N) Worst-Case 
	Function goes level by level finding the next available space. */
	template<class V> 
	auto InsertAnyWhere( V value, BinaryNode<V> *&root ) {
	 queue<BinaryNode<V> *> q;
	 q.push( root );
	 auto newNode = new BinaryNode<V>( value );

	 while( !q.empty() ) {		 
	  auto node = q.front();
		q.pop();
			
	  if( node->Left == nullptr ) {
		 node->Left = newNode;		 
	   break;
	  }

	  if( node->Right == nullptr ) { 
	   node->Right = newNode;
	   break;
	  }

	  q.push( node->Left );
	  q.push( node->Right );
	 } //while end
	   
	 return newNode;
	} //func end

	/*
	 Performs a binary search insert. If a nullptr is passed the
	the function returns the new root. Otherwise, given a root, the 
	function returns the node inserted. Useful for generating bianry
	search trees to run balancing, transversal, and other  algorithms.
	
	
	Complexity: O(logN)
   	Function performs an unsuccessul search and then inserts appropr-
	iately at the last parent found along the path.
	*/

	template<class V>
	auto InsertIntoBST( V value, BinaryNode<V> *&root ) {
	 auto newNode = new BinaryNode<V>( value );
	 auto parent = root;
	 auto node = root;
	 
	 while( node != nullptr ) {
	  parent = node;
	 
	  if( value < node->Value ) {
	   node = node->Left;
	  }
	  else {
	   node = node->Right;
	  }
	 } //while end;
	 
	 if( value < parent->Value ) {
	  parent->Left = newNode;
	 }
	 else {
	  parent->Right = newNode;
	 } 
	 return newNode;
	}//func end
	
 } // namespace BinaryTree end
} //namespace TreeKit end
#endif
