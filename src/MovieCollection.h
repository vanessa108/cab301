#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <string.h>
#include <iostream>
//#include "Movie.h"
#include "MovieBST.h"

using std::cout; using std::endl; using std::cin; using std::string;

/* Represents the collection of movies */ 
class MovieCollection {
public:
    /* binary search tree that stores all movies */
    MovieBST allMovies;
    
    /** Function: takes in user inputs to add a new movie 
    *      If the movie title already exists, the number of copies can be altered */
    void addMovie();

    void removeMovie();
    void displayAllInfo();
    void displayTopTen();
    

private:
    /** Helper function for cout/cin data entries
    *   Input: string containing name of what data is being retrieved
    *   Returns string with the user's input **/
    string dataEntry(string dataName);
    /** Helper function to print out large selection menu for movie genre
    *  returns int of user selection **/
    int getGenre();
    /** Helper function to print out large selection menu for movie classification
     *  returns int of user selection **/
    int getClassification();
};


#endif