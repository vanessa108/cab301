#include<string.h>
#include<iostream>

#include "MovieCollection.h"
//#include "Movie.h"
using std::string; using std::cout; using std::endl;


void MovieCollection::addMovie() {
    cout << endl;
    cin.ignore();
    string title = dataEntry("movie title");
    // check if movie exits

    string actors = dataEntry("starring actor(s)");
    string directors = dataEntry("director(s)");
    getGenre();
    getClassification();
    cout << endl;
    cin.ignore();
    string durS = dataEntry("duration (minutes)");
    string relDateS = dataEntry("release date (year)");
    string numCopS = dataEntry("number of copies available");
    cout << endl;
    int duration = std::stoi(durS);
    int releaseDate = std::stoi(relDateS);
    int numCopies = std::stoi(numCopS);

}



string MovieCollection::dataEntry(string dataName) {
    string input;
    cout << "Enter the " + dataName + ": ";
    getline(cin, input);
    return input; 
}

int MovieCollection::getGenre() {
    char input;
    cout << endl << "Select the genre: " << endl;
    cout << "1. Drama \n2. Adventure \n3. Family \n4. Action" << endl;
    cout <<"5. Sci-Fi \n6. Comedy \n7. Thriller \n8.Other" << endl;
    cout << "Make selection (1-8): ";
    cin>>input;
    if (isdigit(input)) {
        return input;
    } else {
        return 10;
    }

}

int MovieCollection::getClassification() {
    char input;
    cout << endl << "Select the genre: " << endl;
    cout << "1. General (G) \n2. Parental Guidance (PG) \nMature (M) \n4. Mature Accompanied (MA15+)" << endl;
    cout << "Make selection (1-4): ";
    cin>>input;
    if (isdigit(input)) {
        return input;
    } else {
        return 10;
    }

}