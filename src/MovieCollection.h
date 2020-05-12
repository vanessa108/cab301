#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <string.h>
#include <iostream>
//#include "Movie.h"
#include "MovieBST.h"
#include "Member.h"

using std::cout; using std::endl; using std::cin; using std::string;

/* Represents the collection of movies */ 
class MovieCollection {
public:
    /* binary search tree that stores all movies */
    MovieBST allMovies;

    // struct movieBorrowNum {
    //     int numBorrowed;
    //     string movieTitle;
    // };
    // movieBorrowNum mostBorrowed[15];
    Movie mostBorrowed[15];

    void movieArray();
    /** Function: takes in user inputs to add a new movie 
    *      If the movie title already exists, the number of copies can be altered */
    void addMovie();
    void removeMovie();
    void displayAllMovies();
    void displayBorrowed(); 
    void displayTopTen();
    void borrowMovie(Member & currentMember);
    void returnMovie(Member & currentMember);
    

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