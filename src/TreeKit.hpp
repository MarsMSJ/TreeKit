#ifndef _TREEKIT_HPP
#define _TREEKIT_HPP

#include "BinaryTree.hpp"
#include "RandomSource.hpp"
#include <vector>

namespace TreeKit {
	
/*
 Binary Tree Namespace : TreeKit::BinaryTree
*/
namespace BinaryTreeKit {
/*
 Generates a random binary tree with nodes random put everywhere.
This is NOT a binary search tree.
*/
 BinaryNode<int> * GenerateRandomBinaryTree( size_t size, int upperBound ) {
  if( size == 0 ) {
   return nullptr;
  }
  vector<int> V;
  GetRandomIntegers( V,  size, upperBound );
  BinaryNode<int> *root;

  for( auto i : V ) {
   if( root == nullptr ) {
    root = InsertAnyWhere<int>( V[0], nullptr );
    continue;
   }   

   InsertAnyWhere<int>( i, root ); 
  }

  return root;
 }

/*
 Generates a random binary search tree;
*/
 BinaryNode<int> * GenerateRandomBinarySearchTree( size_t size, int upperBound ) {
  if( size == 0 ) {
   return nullptr;
  }
 
  vector<int> V; 
  GetRandomIntegers( V, size, upperBound );
  BinaryNode<int> *root;

  for( auto i :V ) {
   if( root == nullptr ) {
    root = InsertIntoBST<int>( V[0], nullptr );
    continue;
   }   

   InsertAnyWhere<int>( i, root ); 
  }

  return root;
	//Generate Random Binary Heap <int> 
 }
} //namespace Binary Tree end
	
namespace TernaryTreeKit {

        //TO DO
        //Read dictionary file, create TST from dictionary
        //Read dictionary file, select random words to insert into TST:
	} //namespace Ternary Tree end

} //namespace TreeKit end
#endif
