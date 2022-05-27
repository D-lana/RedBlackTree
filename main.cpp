#include "redBlackTree.hpp"
#include "printTree.hpp"

#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>    // std::lexicographical_compare
#include <cctype>   
#include <string>
#include <fstream>


template <typename T>
void print(Tree<T> *tree, const int level = 0)
{
	if (tree->right)
		print(tree->right, level + 1);
	for (int i = 0; i < level; i++)
		std::cout << " ";
	if (tree->color == RED) {
		std::cout << "\x1b[1;31m" << tree->data << "\x1b[0m" << std::endl;
	}
	if (tree->color == BLACK) { 
		std::cout << tree->data << std::endl;
	}
	if (tree->left)
		print(tree->left, level + 1);
}

template <typename T>
void printChild(Tree<T> *tree, int i, int deep, std::string treeString) {
	std::string str;
  	str.assign(i, ' ');
	//if (tree->left || tree->right)
	std::cout << "Deep: " << deep << std::endl;
	if(tree->left) {
		if (tree->left->color == RED) {
			std::cout << str << "\x1b[1;31m" << tree->left->data << " \x1b[0m";
		}
		else {
			std::cout << str <<  tree->left->data << " ";
		}
	}
	if (tree->right) {
		
		if (tree->right->color == RED) {
			std::cout << str << "\x1b[1;31m" << tree->right->data << " \x1b[0m";
		}
		else {
			std::cout << str << tree->right->data << " ";
		}
	}
	if(tree->parent) {
		if (tree->parent->right == tree) {
			std::cout << std::endl;
		}
	}
	deep++;
	if(tree->right) {
		printChild(tree->right, i / 2, deep, treeString);
	}
	if(tree->left) {
		printChild(tree->left, i / 2, deep, treeString);
	}
}

// template <typename T>
// void printTree(Tree<T> *tree) {
// 	std::string treeString;
// 	printChild(tree, 8, 1, treeString);
// }


int main() {
	redBlackTree<int> tree_1 = redBlackTree<int>();
	tree_1.insert(5);
	tree_1.insert(20);
	tree_1.insert(15);
	tree_1.insert(27);
	tree_1.insert(3);
	tree_1.insert(1);
	tree_1.insert(2);
	tree_1.insert(8);
	tree_1.insert(30);
	tree_1.insert(6);
	tree_1.insert(31);
	tree_1.insert(10);
	tree_1.insert(11);
	//tree_1.insert(33);
	print(tree_1.getTree(), 0);

	printTree<int> tree_print = printTree<int>(*tree_1.getTree(), 16);
	tree_print.print();
	//printTree(tree_1.getTree());
	//std::cout << "HEAD: " << tree_1.getTree()->data << std::endl;
	// std::set<int> set_1;
	// set_1.insert(1);
	// set_1.insert(2);
	// set_1.insert(3);
	// std::set<int>::iterator it_1 = set_1.begin();
	// std::set<int>::iterator it_1end = set_1.end();
	// std::set<int> set_2;
	// set_2.insert(1);
	// set_2.insert(2);
	// set_2.insert(4);
	// //set_2.insert(4);
	// std::set<int>::iterator it_2 = set_2.begin();
	// std::set<int>::iterator it_2end = set_1.end();
	// std::cout << std::lexicographical_compare(it_1, it_1end, it_2, it_2end) << std::endl;

}
