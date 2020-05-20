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
    
    /* Function: insert movie into a tree 
    *   Input: movie object */
    void insertMovie(Movie newMovie);
    
    /* Function: display all movies in the tree in alphabetical order */
    void inOrder();

    /* Function: finds movie node in tree
    *   Input: string of movie title
    *   Output: pointer to a movie object, null ptr if no movie found */
    Movie * findMovie(string movieTitle);

    /** Function: returns the number of nodes */
    int treeSize();

    /** Function: converts nodes in tree to an array
     *  Input: array of movie objects */
    void treeToArray(Movie mostBorowed[]);

    /** Function: removes a movie node from tree
     *  Input: title of movie to be delete */
    void deleteMovie(string movieTitle);
    
    /** Helper function: displays BST in preorder
     *  Only used to assist with debugging for node deletion */
    void preOrder();
     
private:
    /* Find a movie that matches a given title, called recursively to go down tree
     *  Input: movie title (string), reference to pointer of movie node
     *  Output: Reference to a pointer of a movie object */
    MovieNode *& _findMovie(string movieTitle, MovieNode * &node);

    /* Inserts movie into the BST
     *  Input: movie object, ref to pointer of movie node
     *  Initially takes root node and then is called recursively    */
    void _insertMovie(Movie newMovie, MovieNode * &node);

    /* Retrieves and prints the movies in the BST in alphabetical order
     *  Input: ref to pointer of movie node
     *  Initially takes root node and then is called recursively  */
    void _inOrder(MovieNode * &root);

    /** Main function to find tree size
     * Called recursively
     * Output: number of nodes in subtree */
    int _treeSize(MovieNode * &node);

    /** Main function to convert the tree to an array
     * Input: Movie array, root node, next index in the array 
     * Output: index to next position in array */
    int _treeToArray(Movie mostBorrowed[], MovieNode * &node, int i);

    /** Retrieves and prints movies from BST in preorder
     *  Assists with debugging */
    void _preOrder(MovieNode * &root);
};



#endif 