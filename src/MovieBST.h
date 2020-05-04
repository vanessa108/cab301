#ifndef MOVIEBST_H
#define MOVIEBST_H

#include "Movie.h"
#include "MovieCollection.h"

class MovieNode {
public:
    Movie data;
    MovieNode * left;
    MovieNode * right;
    //initialiser
    MovieNode(Movie data): 
    data{data}, left{nullptr}, right{nullptr} {}

};

class MovieBST {
public:
    //default empty initialiser
    MovieBST(): root{nullptr} {}
    MovieNode * root;
    // add movie to tree
    void insertMovie(Movie newMovie);
    //displays movie in order
    void inOrder();
    // Returns pointer to a movie with given movie title
    // Null pointer if no movie is found
    Movie * findMovie(string movieTitle);
private:
    //helper function to pass local private root
    MovieNode *& _findMovie(string movieTitle, MovieNode * &node);
    void _insertMovie(Movie newMovie, MovieNode * &node);
    void _inOrder(MovieNode * &root);
    
    void deleteMovie();

};








#endif 