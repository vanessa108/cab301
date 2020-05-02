#ifndef MOVIE_H
#define MOVIE_H

#include <string.h>
#include <vector>
using std::string;

class Movie {
public:
    //default initialiser 
    Movie() {
        
    }
    // initialise with values
    Movie(string _title, string _actors, string _directors, int _genre, int _classification, 
    int _duration, int _releaseDate):
    title{_title}, 
    actors{_actors}, directors{_directors},
    genre{_genre}, classification{_classification},
    duration{_duration}, releaseDate{_releaseDate} {

    }

    void displayInfo();
        
    int numCopies;
    int numAvailable;
    int numTimesBorrowed;


private:
    string getGenre(int code);
    string getClassification(int code);
    string title;
    string actors;
    string directors;
    int genre;
    int classification;
    int duration;
    int releaseDate;

};



#endif