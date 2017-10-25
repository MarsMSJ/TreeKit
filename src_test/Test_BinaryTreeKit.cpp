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
				str+= node->Value;
				
				if( node->Left != nullptr ) {
					s.push( node->Left );
				}
				else {
					str+="X";
				}
				if( node->Right != nullptr ) {
					s.push( node->Right );
				}
				else {
					str+="X";
				}			
			}
			
			return str;
		}
		
	TEST( Test_BinaryTreeKit, InsertAnyWhere ) {
		string input = "ABCDEF";
		string test_preorder = "ABDXXEXXCFXXX";
		bst::BinaryNode<char> *root = nullptr;
		
		for( auto c : input ) {
			if( root == nullptr ) {
				root = bst::InsertAnyWhere<char>( c, nullptr );
				continue;
			}		
			std::cout << c << std::endl;
			bst:InsertAnyWhere( c, root );
		}
		
		// auto GetPreOrderStr = []( bst::BinaryNode<char> *root ){
		// 	stack<BinaryNode<char> *> s;
		// 	s.push( root );
		// 	string str = "";
			
		// 	while( !s.empty() ) {
		// 		auto node = s.top(); s.pop();
		// 		str+= node->Value;
				
		// 		if( node->Left != nullptr ) {
		// 			s.push( node->Left );
		// 		}
		// 		else {
		// 			str+="X";
		// 		}
		// 		if( node->Right != nullptr ) {
		// 			s.push( node->Right );
		// 		}
		// 		else {
		// 			str+="X";
		// 		}			
		// 	}
		// }
		
		string output = GetPreOrderStr(root);
	
		//EXPECT_EQ( output, test_preorder);
		EXPECT_TRUE( output == test_preorder);
		
	}
}