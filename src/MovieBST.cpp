#include<string.h>
#include<iostream>

#include "MovieCollection.h"
#include "Movie.h"
#include "MovieBST.h"

using std::string; using std::cout; using std::endl;

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
        _inOrder(root->left);
        root->data.displayInfo();
        cout << endl;
        _inOrder(root->right);
    }
} 

Movie * MovieBST::findMovie(string movieTitle) {
    return &_findMovie(movieTitle, root)->data;

}

MovieNode *& MovieBST::_findMovie(string movieTitle, MovieNode * &node) {
    if (node == nullptr or node->data.title == movieTitle) {
        return node;
    } else {
        string currentTitle = node->data.title;
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