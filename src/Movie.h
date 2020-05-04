#ifndef MOVIE_H
#define MOVIE_H

#include <string.h>
#include <vector>
using std::string;

/* Represents a movie object (a unique movie title) */
class Movie {
public:
    /* Default initialiser */
    Movie() {
        
    }

    /* Initialise movie with values */
    Movie(string _title, string _actors, string _directors, int _genre, int _classification, 
    int _duration, int _releaseDate, int _numCopies):
        title{_title}, 
        actors{_actors}, 
        directors{_directors},
        genre{_genre}, 
        classification{_classification},
        duration{_duration}, 
        releaseDate{_releaseDate},
        numCopies{_numCopies}, 
        numAvailable{_numCopies}{
    }

    /* Display all information about the movie */
    void displayInfo();

    string title;   // unique identifier for a movie
    int numCopies;  
    int numAvailable;
    int numTimesBorrowed = 0;
    
private:
    /* Helper function to display which genre/classification depending on input selection (int)
        Return string with genre/class */
    string getGenre(int code);
    string getClassification(int code);
    // movie details 
    string actors;
    string directors;
    int genre;
    int classification;
    int duration;
    int releaseDate;

};


#endif