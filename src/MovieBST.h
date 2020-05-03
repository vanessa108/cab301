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

    void insertMovie(Movie newMovie);
private:
    void _insertMovie(Movie newMovie, MovieNode * &node);
    void findMovie();
    void deleteMovie();

};








#endif 