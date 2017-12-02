#ifndef _TREEKIT_HPP
#define _TREEKIT_HPP

#include "BinaryTree.hpp"
#include "RandomSource.hpp"
#include <vector>
#include <initializer_list>

namespace TreeKit {
	
/*
 Binary Tree Namespace : TreeKit::BinaryTree
*/
namespace BinaryTreeKit {
/*
 Generates a random binary tree with nodes random put everywhere.
This is NOT a binary search tree.
*/

/**
 Usage: auto rootNode = GetBinaryTree( { 4, 5, 12, 3 } ) 
 	auto rootNode = GetBinaryTree( {"cat", "dog", "rabbit"} )
*/
 template <class T>
 auto GetBinaryTree( std::initializer_list<T> initList ){
  bool isFirstValue = true;
  auto root = new BinaryNode<T>( initList[0] );/*!< Pointer to the root of the tree */

  for( auto item : initList ) {
   if( isFirstValue ) {
    isFirstValue = false;
    continue;
   }

   InsertNextAvailable<T>( item, root );
  }
  return root; /*!< BinaryNode pointer to the root is returned to the caller */
 }

/**
 Returns the root to a binary tree generatedd from a random sequence of integers.
 \param upperBound Default value is 10. 
*/
 BinaryNode<int> * GenerateRandomBinaryTree( size_t size, int upperBound = 10 ) {
  if( size == 0 ) {
   return nullptr;
  }
  vector<int> V;
  GetRandomIntegers( V,  size, upperBound );
  auto root = new BinaryNode<int>(0); /*!< Pointer to the root of the tree */

  for( auto i : V ) {
   if( root == nullptr ) {
     root->Value = V[0];
     continue;
   }   

   InsertNextAvailable<int>( i, root ); 
  }
  return root; /*!< BinaryNode pointer to the root is returned to the caller */
 }

/**
 Usage: auto rootNode = GetBinarySearchTree( { 4, 5, 12, 3 } ) 
 	auto rootNode = GetBinarySearchTree( {"cat", "dog", "rabbit"} )
*/
 template <class T>
 auto GetBinarySearchTree( std::initializer_list<T> initList ){
  bool isFirstValue = true;
  auto root = new BinaryNode<T>( initList[0] );/*!< Pointer to the root of the tree */

  for( auto item : initList ) {
   if( isFirstValue ) {
    isFirstValue = false;
    continue;
   }

   InsertIntoBST<T>( item, root );
  }
  return root; /*!< BinaryNode pointer to the root is returned to the caller */
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
    root->Value = V[0];
    continue;
   }   

   InsertNextAvailable<int>( i, root ); 
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
