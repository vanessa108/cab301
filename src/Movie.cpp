#include<string.h>
#include<iostream>
#include "Movie.h"

using std::string; using std::cout; using std::endl;

void Movie::displayInfo() {
    cout << "Title: " << title << endl;
    cout << "Starring: " << actors << endl;
    cout << "Director: " << directors << endl;
    cout << "Genre: " << getGenre(genre) << endl;
    cout << "Classification: " << getClassification(classification) << endl;
    cout << "Duration: " << duration << endl;
    cout << "Release Date: " << releaseDate << endl;
    cout << "Copies Available: " << numAvailable << endl;
    cout << "Total Copies: " << numCopies << endl;
    cout << "Times Rented: " << numTimesBorrowed << endl;

}


string Movie::getGenre(int code) {
    switch (code) {
    case '1':
        return "Drama";
    case '2':
        return "Adventure";
    case '3':
        return "Family";
    case '4': 
        return "Action";
    case '5':
        return "Sci-Fi";
    case '6':
        return "Comedy";
    case '7':
        return "Thriller";
    case '8':
        return "Other";
    default:
        return "Misc.";
    }
}

string Movie::getClassification(int code) {
    switch (code) {
    case '1':
        return "General (G)";
    case '2':
        return "Parental Guidance (PG)";
    case '3':
        return "Mature (M)";
    case '4': 
        return "Mature Accompanied (MA15+)";
    default:
        return "Unknown";
    }

}