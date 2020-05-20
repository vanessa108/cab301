#include<string.h>
#include<iostream>

#include "MovieCollection.h"
#include "Movie.h"
#include "MovieBST.h"

using std::string; using std::cout; using std::endl;

int MovieBST::treeSize() {
    return _treeSize(root);
}

int MovieBST::_treeSize(MovieNode * &node) {
    if (node == nullptr) {
        return 0;
    } else {
        return (_treeSize(node->left) + 1 + _treeSize(node->right));
    }
}
void MovieBST::insertMovie(Movie newMovie) {
    _insertMovie(newMovie, root);
}

void MovieBST::_insertMovie(Movie newMovie, MovieNode * &node) {
    if (node == nullptr) {
        node = new MovieNode(newMovie);
    } else {
        string currentTitle = node->data.title;
        string newTitle = newMovie.title;
        int titleComparison = strcmpi(currentTitle.c_str(), newTitle.c_str());
        if (titleComparison < 0) {
            //put movie on right
            _insertMovie(newMovie, node->right);
        } else if (titleComparison > 0) {
            //movie on right
            _insertMovie(newMovie, node->left);
        }        
    }
}

void MovieBST::inOrder() {
    _inOrder(root);
}

void MovieBST::_inOrder(MovieNode * &root) {
    if (root != nullptr) {
        //inorder on left subtree
        _inOrder(root->left);
        root->data.displayInfo();
        cout << endl;
        //inorder on right subtree
        _inOrder(root->right);
    }
} 

Movie * MovieBST::findMovie(string movieTitle) {
    return &_findMovie(movieTitle, root)->data;

}

MovieNode *& MovieBST::_findMovie(string movieTitle, MovieNode * &node) {
    //movie found, or tree has been traversed so movie does not exist
    if (node == nullptr or node->data.title == movieTitle) {
        return node;
    } else {
        string currentTitle = node->data.title;
        //compares string in alphabetical order
        int titleComparison = strcmpi(currentTitle.c_str(), movieTitle.c_str());
        if (titleComparison < 0) {
            //put movie on right
            return _findMovie(movieTitle, node->right);
        } else {
            //movie on right
            return _findMovie(movieTitle, node->left);
        }        
    }
}

void MovieBST::treeToArray(Movie mostBorrowed[]) {
    //start at first item in array
    _treeToArray(mostBorrowed, root, 0);
}

int MovieBST::_treeToArray(Movie mostBorrowed[], MovieNode * &node, int i) {
    if (node == nullptr) {return 0;}
    //transfer movie object to array 
    mostBorrowed[i] = node->data;
    // index to next item in array
    i++;
    //repreat for left tree
    if (node->left != nullptr) {
        i = _treeToArray(mostBorrowed, node->left, i);
    }
    //repeat for right tree
    if (node->right != nullptr) {
        i = _treeToArray(mostBorrowed, node->right, i);
    }
    return i;

}

void MovieBST::deleteMovie(string movieTitle) {
    MovieNode *& toBeDeleted = _findMovie(movieTitle, root);
    //case 1: node is leaf
    if (toBeDeleted->left == nullptr and toBeDeleted->right == nullptr) {
        //cout << "case 1" << endl;
        toBeDeleted = nullptr;
    }
    //case 2: node has one child
    else if (toBeDeleted->left == nullptr or toBeDeleted->right == nullptr) {
        //cout << "case 2" << endl;
        MovieNode *& tempNewNode = toBeDeleted;
        if (toBeDeleted->left == nullptr) {
            tempNewNode = toBeDeleted->right;
        } else {
            tempNewNode = toBeDeleted->left;
        }
        if (toBeDeleted == root) {
            root = tempNewNode;
            toBeDeleted = tempNewNode;
        }
    }
    //case 3: two children
    else {
        if (toBeDeleted->left->right == nullptr) {
            //cout << "case 3.1" << endl;
            toBeDeleted->data = toBeDeleted->left->data;
            toBeDeleted->left = toBeDeleted->left->left;
        } else {
            //cout << "case 3.2" << endl;
            MovieNode *tempParent = toBeDeleted;
            MovieNode *tempChild = toBeDeleted->left;
            while (tempChild->right != nullptr) {
                tempParent = tempChild;
                tempChild = tempChild->right;
            }
            toBeDeleted->data = tempChild->data;
            tempParent->right = tempChild->left;
        } 
    }
}

void MovieBST::preOrder() {
    _preOrder(root);
}

void MovieBST::_preOrder(MovieNode *&root) {
    if (root != nullptr) {
        cout << root->data.title << "|";
        _preOrder(root->left);
        _preOrder(root->right);
    }
}