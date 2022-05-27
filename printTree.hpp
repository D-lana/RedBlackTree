#ifndef printTree_HPP
#define printTree_HPP

#include <iostream>
#include "redBlackTree.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>

template <typename T>
class printTree {
	private:
	int count;
	Tree<T> &tree;
	int deep;
	std::string *treeString;
	public:

	std::ofstream ofs;
	std::ifstream inf;

	printTree(const printTree &copy) : tree(copy.tree) {
		this->count = copy.count;
		this->deep = copy.deep;
	}

	printTree(Tree<T> &tree_, int count) : tree(tree_) {
		//tree = tree_;
		deep = 0;
		this->count = count;
		treeString = new std::string[5];
		//ofs("test.txt", std::ofstream::out);
	}

	~printTree() {
		
	}

	void print() {
		ofs.open("test.html", std::ofstream::out | std::ofstream::trunc);
		//ofs("test.txt", std::ofstream::out);
		std::string str;
		std::string buf;
		std::string final;
		str.assign(count, ' ');
		std::cout << str << tree.data << std::endl;
		ofs << str << tree.data << std::endl;
		printChild(&tree, count / 3, deep);
		// for(int i = 0 ; !treeString[i].empty(); ++i) {
		// 	std::cout << treeString[i] << std::endl;
		// }
		//ofs << str << deep << std::endl;
		ofs.close();
		//inf.open("test2.html", std::ifstream::in);
		// size_t first;
		// size_t len;
		//int tab = pow(2, deep);
		// for (int i = 0; deep - 1 > i; ++i) {
		// 	ofs << str.assign(tab, ' ') << treeString[deep];
		// }
		//ofs.close();
	}

	void printChild(Tree<T> *tree, int i, int deep) {
		std::string str;
		std::string buffer;
		str.assign(i, ' ');
		if (deep > this->deep) {
			this->deep = deep;
		}
		//std::cout << "Deep: " << deep << std::endl;
		if(tree->left) {
			if (tree->left->color == RED) {
				ofs << "deep" << deep << str << "<b style=\"color:red\">" << tree->left->data << "</b>";
				//std::cout << str << "\x1b[1;31m" << tree->left->data << " \x1b[0m";
				this->treeString[deep].append("<b style=\"color:red\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->left->data) + "</b>");
			}
			else {
				ofs  << "deep" << deep << str << "<b style=\"color:black\">" << tree->left->data << "</b>";
				//std::cout << str <<  tree->left->data << " ";
				this->treeString[deep].append("<b style=\"color:black\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->left->data) + "</b>");
			}
		}
		if (tree->right) {
			if (tree->right->color == RED) {
				ofs  << "deep" << deep << str << "<b style=\"color:red\">" << tree->right->data << "</b>";
				//std::cout << str << "\x1b[1;31m" << tree->right->data << " \x1b[0m";
				this->treeString[deep].append("<b style=\"color:red\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->right->data) + "</b>");
			}
			else {
				ofs  << "deep" << deep << str << "<b style=\"color:black\">" << tree->right->data << "</b>";
				//std::cout << str << tree->right->data << " ";
				this->treeString[deep].append("<b style=\"color:black\">" + str.assign(pow(2, deep), ' ') + std::to_string(tree->right->data) + "</b>");
			}
		}
		// if(tree->parent) {
		// 	if (tree->parent->right == tree) {
		// 		std::cout << std::endl;
		// 	}
		// }
		deep++;
		if(tree->right) {
			printChild(tree->right, i / 2, deep);
		}
		if(tree->left) {
			printChild(tree->left, i / 2, deep);
	}
}

};

#endif
