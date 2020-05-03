#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <string.h>
#include <iostream>
//#include "Movie.h"
#include "MovieBST.h"

using std::cout; using std::endl; using std::cin; using std::string;


class MovieCollection {
public:
    MovieBST allMovies;

    void addMovie();
    void removeMovie();
    void displayAllInfo();
    void displayTopTen();
    

private:
    // menu and user input functions
    string dataEntry(string dataName);
    int getGenre();
    int getClassification();
};


#endif