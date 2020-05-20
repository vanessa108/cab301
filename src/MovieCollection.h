#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include <string.h>
#include <iostream>
//#include "Movie.h"
#include "MovieBST.h"
#include "Member.h"
#include "MemberCollection.h"

using std::cout; using std::endl; using std::cin; using std::string;

/* Represents the collection of movies */ 
class MovieCollection {
public:
    /* binary search tree that stores all movies */
    MovieBST allMovies;

    Movie movieArray[15];

    void mostBorrwowed();
    /** Function: takes in user inputs to add a new movie 
    *      If the movie title already exists, the number of copies can be altered */
    void addMovie();
    /** Function: takes in user input to remove a movie
     *     Can remove a copy of a movie or remove entire movie from library */
    void removeMovie();
    /** Function: prints all movies and movie details in alphabetical order */
    void displayAllMovies();
    /** Function: lists all the movies currently held by a member */
    void displayBorrowed(); 
    /** Function: lists the top 10 most borrowed movies, from most borrowed to least
     *  First converts BST to array, then applies quicksort */
    void displayTopTen();
    /** Function: allows user to borrow movie 
     *   Input: Index to current member in member array, member array  */
    void borrowMovie(int currentMember, MemberCollection & memberCol);
    /** Function: allows user to return movie 
     *   Input: Index to current member in member array, member array  */
    void returnMovie(int currentMember, MemberCollection & memberCol);
    

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
    /** Function: primary quick sort function
     *  Input: movie array, left and right sides of the array
     *  Called recursively until array sorted */
    void quickSort(Movie * movies, int l, int r);
    /** Function: partition based of Hoare's partitioniing
     * Returns a pivot for the quick sort */
    int partition(Movie * movies, int l, int r);
    /** Helper function to swap two elements in the array */
    void swap(Movie *a, Movie *b);

};
#endif