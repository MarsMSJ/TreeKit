#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

namespace TreeKit {
 namespace TernaryTreeKit {

	/*
	 Simple node class with left, center, and right child links. Includes
	an optional count field. The count field is useful for repr-
	esenting duplicate values without storing them. Another use-
	ful function is to store the count of nodes below a given
	node.
	*/
	class TeraryNode{
	 public: 
	  char Character;
	  BinaryNode *Left;
          BinaryNode *Center;
	  BinaryNode *Right;

	//Constructor, for convenience
	  TernaryNode( char c ) {
	   Character = c; 
           Left = Center = Right = nullptr;
	  }
	 
	};//class end


	/*
	 Performs a ternary search insert. If a nullptr is passed the
	the function returns the new root. Otherwise, given a root, the 
	function returns the node inserted. Useful for generating bianry
	search trees to run balancing, transversal, and other  algorithms.
	
	
	Complexity: O(logN)
   	Function performs an unsuccessul search and then inserts appropr-
	iately at the last parent found along the path.
	*/

	auto InsertIntoTST( string str, TernaryNode *root ) {
         if( str.empty() ) {
          return nullptr;
         }

        //Do we have a starting point?
	 if( root == nullptr ) {
	  root = new TernaryNode( str[0] );
	 }
	
         auto node = root;
         auto parent = root;
         auto lastNode = root;
         //Perform an unsuccessful search. Insert where path ends.
         for( auto c : str ) {
          
          while( node != nullptr ) {
           parent = node;

           if( node->Character == c ) {
            node = node->Center;
            break; //Node exist, go center and break
           }

           if( node->Character < c ) {
            node = node->Right;
           }
 
           if( node->Character > c ) {
            node = node->Left; 
           }
          }

          if( node == nullptr ) {
           node = new TernaryNode( c );
           if( parent->Character > c ) {
            parent->Left = node;
           }
           else {
            parent->Right = node;
           }
           lastNode = node;
          }
         } //for end 
	 //Return last node touched/created
	 return lastNode;
	}//func end
 } // namespace TernaryTree end
} //namespace TreeKit end
#endif
