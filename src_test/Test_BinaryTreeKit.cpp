#include <string>
#include <stack>
#include "gtest/gtest.h"
#include "../src/BinaryTree.hpp"
#include <iostream>

namespace bst = TreeKit::BinaryTreeKit;

namespace{
		
	//Helper function
		auto GetPreOrderStr ( bst::BinaryNode<char> *root ){
			stack<bst::BinaryNode<char> *> s;
			s.push( root );
			string str = "";
			
			while( !s.empty() ) {
				auto node = s.top(); s.pop();
				
				if( node == nullptr ) {
					str+= "X";
					continue;
				}
				str+= node->Value;		
			  s.push( node->Right );
				s.push( node->Left );					
			}
			return str;
		}
		
	TEST( Test_BinaryTreeKit, InsertNextAvailable_GeneralTest) {
		string input = "ABCDEF";
		string test_preorder = "ABDXXEXXCFXXX";
		bst::BinaryNode<char> *root = nullptr;
		
		for( auto c : input ) {
			if( root == nullptr ) {
				root = new bst::BinaryNode<char>( c );
				continue;
			}		
			bst::InsertNextAvailable<char>( c, root );
		}
		string output = GetPreOrderStr(root);
		EXPECT_EQ( output, test_preorder);
	}
	
	TEST( Test_BinaryTreeKit, InsertIntoBST_GeneralTest ) {
		string input = "CBEAFD";
		string test_preorder = "CBAXXXEDXXFXX";
		bst::BinaryNode<char> *root = nullptr;
		
		for( auto c : input ) {
			if( root == nullptr ) {
				root = new bst::BinaryNode<char>( c );
				continue;
			}		
			bst::InsertIntoBST<char>( c, root );
		}
		std::cout << test_preorder << std::endl;
		string output = GetPreOrderStr(root);
		std::cout << output << std::endl;
		EXPECT_EQ( output, test_preorder);
	}
}
