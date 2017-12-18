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
	 Insert's into the next available position in the tree. We must 
	 declare a root for the tree with an intial value. Otherwise, 
	 given a root, the function returns the node inserted. Use-
	 ful for generating random binary trees.
	
 	Time Complexity: O(N) Worst-Case 
	Function goes level by level finding the next available space. */
	template<class V> 
	void InsertNextAvailable( V&& value, BinaryNode<V> *&root ) {
	 queue<BinaryNode<V> *> q;
	 q.push( root );

	 while( !q.empty() ) {		 
	  auto node = q.front();
		q.pop();
			
	  if( node->Left == nullptr ) {
           node->Left = new BinaryNode<V>( value );		 
	   break;
	  }

	  if( node->Right == nullptr ) { 
	   node->Right = new BinaryNode<V>( value );
	   break;
	  }

	  q.push( node->Left );
	  q.push( node->Right );
	 } //while end
	} //func end

	/*
	 Performs a binary search insert. An root node initialized with 
	 an initial value is required. Given the root, the fuction returns
	 returns the node inserted. Useful for generating bianry search
	 trees.
	
	Complexity: O(logN)
   	Function performs an unsuccessul search and then inserts appropr-
	iately at the last parent found along the path.
	*/

	template<class V>
	void InsertIntoBST( V&& value, BinaryNode<V> *&root ) {
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
	  parent->Left = new BinaryNode<V>( value );
	 }
	 else {
	  parent->Right = new BinaryNode<V>( value );
	 } 
	}//func end
	
 } // namespace BinaryTree end
} //namespace TreeKit end
#endif
