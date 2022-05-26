#ifndef redBlackTree_HPP
#define redBlackTree_HPP

#include <iostream>

enum Color { Black, Red };

template<class T>
struct  Tree
{
	T data;
	Color color;
	Tree *left;
	Tree *right;
	Tree *parent;
};

template<class T>
class redBlackTree {
    private:
    Tree<T> *tree;
    size_t count;
    public:
    
    
    redBlackTree() {
       tree = NULL; 
       count = 0;
    }
    
    ~redBlackTree() {
        
    }
    
    void insert(const T& _data) {
        if (tree == NULL)
        {
            tree = new Tree<T>;
            tree->left = NULL;
            tree->right = NULL;
            tree->data = _data;
            tree->color = Black;
            count++;
        }
        else
        {
            Tree<T> *newtree;
            newtree = new Tree<T>;
            Tree<T> *tmp = tree;
            newtree->right = NULL;
            newtree->left = NULL;
            newtree->data = _data;
            newtree->color = Red;
            lookForPlace(newtree, tmp, _data); 
            if (newtree->parent->color == Red) {
                if (newtree->parent->left == newtree) {
                    rightRotate(newtree->parent);
                }
                else {
                    leftRotate(newtree->parent);
                }
            }
        }
    }
        
    void lookForPlace(Tree<T> *newtree, Tree<T> *tmp, const T& _data)
    {
        if (_data == tmp->data) {
            delete newtree;
            return ;
        }
        else
        {
            if (_data < tmp->data)
            {
                if (tmp->left != NULL) {
                    tmp = tmp->left;
                    lookForPlace(newtree, tmp, _data);
                }
                else {
                    tmp->left = newtree;
                    newtree->parent = tmp;
                    return ;
                }
            }
            else if (_data > tmp->data)
            {
                if (tmp->right != NULL) {
                    tmp = tmp->right;
                    lookForPlace(newtree, tmp, _data);
                }
                else {
                    tmp->right = newtree;
                    newtree->parent = tmp;
                    return ;
                }
            }
            //coloration(newtree);
        }
    }
    
    void leftRotate(Tree<T> *rotate) {
        std::cout << "leftRotate" << rotate->data << std::endl;
        Tree<T> *tmp = rotate->parent;
        if (rotate->parent->parent != NULL) {
            rotate->parent = rotate->parent->parent; //1
            tmp->parent->right = rotate; //2
            tmp->parent = rotate; //3
            if (rotate->left) {
                tmp->right = rotate->left; // 4
                rotate->left->parent = tmp->right;
                rotate->left = tmp;
            }
            else {
                tmp->right = NULL;
                rotate->left = tmp;
            }
        }
        else {
            tmp->parent = rotate;
            rotate->parent = NULL;
            if (rotate->left) {
                tmp->right = rotate->left;
                rotate->left->parent = tmp->right;
                rotate->left = tmp->right;
            }
            else {
                tmp->right = NULL;
                rotate->left = tmp;
            }
            this->tree = rotate;
            this->tree->color = Black;
        }
        tmp->color = Red;
        rotate->color = Black;
    }
    
    void rightRotate(Tree<T> *rotate) {
        std::cout << "rightRotate" << std::endl;
        Tree<T> *tmp = rotate->parent;
        if (rotate->parent->parent != NULL) {
            rotate->parent = rotate->parent->parent;
            tmp->parent = rotate;
            rotate->parent->left = rotate;
            if (rotate->right) {
                tmp->left = rotate->right;
                rotate->right->parent = tmp->left;
                rotate->right = tmp->left;
            }
            else {
                tmp->left = NULL;
                rotate->right = tmp;
            }
        }
        else {
            tmp->parent = rotate;
            rotate->parent = NULL;
            if (rotate->right) {
                tmp->left = rotate->right;
                rotate->right->parent = tmp->left;
                rotate->right = tmp->left;
            }
            else {
                tmp->left = NULL;
                rotate->right = tmp;
            }
            this->tree = rotate;
            this->tree->color = Black;
        }
        tmp->color = Red;
        rotate->color = Black;
    }
    
    Tree<T> *getTree() {
        return tree;
    }
    
};

#endif
