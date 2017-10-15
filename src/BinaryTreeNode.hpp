#ifdef _BINARYTREENODE_HPP
#define _BINARYTREENODE_HPP

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

namespace TreeKit {

	/*
	 Simple node class with left and right child links. Includes
	an optional count field for storing duplicate values with one
	node.
	*/
	template<class V>
	class BinaryTreeNode{
	 public: 
	  V Value;
	  BinaryTreeNode *Left;
	  BinaryTreeNode *Right;

	/* This is optional. Used when storing duplicate
	values with the same tree node. Normally, for
	duplicate values, we create a duplicate node for
	the value.
	*/
	  size_t Count; //For storing duplicate values

	//Constructor, for convenience
	  BinaryTreeNode( V value ) {
	   Value = value; 
	   Count = 1;
	  }

	//Insert for stacking duplicate values
	 
	};//class end

	/* Insert's into the next available position in the tree. If a nullptr
	pointer is passed for the root, the function returns the new root. 
	Otherwise, given a root, the function returns the node inserted. 

 	Time Complexity: O(logN)
	Function goes level by level finding the next available space. */
	template<class V> 
	auto InsertAnyWhere( V value, BinaryTreeNode<V> *root ) {
	 if( root == nullptr ) {
	  return new BinaryTreeNode( value );
	 }

	 queue<BinaryTreeNode<V> *> q;
	 q.push( root );
	 auto newNode = new BinaryTreeNode<V>( value );

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

	/* Performs a binary search insert. If a null point is passed the
	the function returns the new root. 
	Otherwise, given a root, the function returns the node inserted.
	
	Complexity: O(logN)
   	Function performs an unsuccessul search and the insert appropriately.
	  */

	template<class V>
	auto InsertIntoBST( V value, BinaryTreeNode *root ) {
	 if( root == nullptr ) {
	  return new BinaryTreeNode( value );
	 }

	 auto newNode = new BinaryTreeNode<V>( value );
	 auto parent = root;
	 auto node = root;
	 stack<BinaryTreeNode<V>> s;
	 s.push( node );

	 while( node != nullptr ) {
	  parent = node;
	  node = s.top();
	  s.pop();

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

	} //namespace end
#endif
