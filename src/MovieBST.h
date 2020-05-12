#ifndef MOVIEBST_H
#define MOVIEBST_H

#include "Movie.h"
#include "MovieCollection.h"

/* Represents a node containing a movie */
class MovieNode {
public:
    /* movie object */
    Movie data;
    /* Pointers to left and right nodes */
    MovieNode * left;
    MovieNode * right;
    /* Default initialise with movie object and null pointers */
    MovieNode(Movie data): 
    data{data}, left{nullptr}, right{nullptr} {}
};

/* Represents a binary search tree that stores all movies */
class MovieBST {
public:
    /* Default empty initialiser */
    MovieBST(): root{nullptr} {}

    /* root is a pointer to a movie node */
    MovieNode * root;
    
    /* Public function to insert movie into a tree 
    *   Input: movie object
    */
    void insertMovie(Movie newMovie);
    
    /* Public function to display all movies in the tree in alphabetical order */
    void inOrder();

    /* Public function to find movie 
    *   Input: string of movie title
    *   Output: pointer to a movie object, null ptr if no movie found
    */
    Movie * findMovie(string movieTitle);

    int treeSize();

    void treeToArray(Movie mostBorowed[]);
     
private:
    /* Find a movie that matches a given title, called recursively to go down tree
     *  Input: movie title (string), reference to pointer of movie node
     *  Output: Reference to a pointer of a movie object
     */
    MovieNode *& _findMovie(string movieTitle, MovieNode * &node);

    /* Inserts movie into the BST
     *  Input: movie object, ref to pointer of movie node
     *  Initially takes root node and then is called recursively 
     */
    void _insertMovie(Movie newMovie, MovieNode * &node);

    /* Retrieves and prints the movies in the BST in alphabetical order
     *  Input: ref to pointer of movie node
     *  Initially takes root node and then is called recursively 
     */
    void _inOrder(MovieNode * &root);
    
    int _treeSize(MovieNode * &root);

    int _treeToArray(Movie mostBorrowed[], MovieNode * &node, int i);
    void _deleteMovie(MovieNode * &root);

};








#endif 