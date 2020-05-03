#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <string.h>
#include <iostream>
#include "Movie.h"

using std::cout; using std::endl; using std::cin; using std::string;

class MovieNode {
public:
    Movie data;
    MovieNode * left;
    MovieNode * right; 

};


class MovieCollection {
public:
    void addMovie();
    void removeMovie();
    void displayAllInfo();
    void displayTopTen();
    //BST functions
    MovieNode root;
    void insertMovie(Movie newMovie, MovieNode * root);
    void findMovie();
    void deleteMovie();

    // menu and user input functions
    string dataEntry(string dataName);
    int getGenre();
    int getClassification();



};


#endif