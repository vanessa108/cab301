#include<string.h>
#include<iostream>

#include "MovieCollection.h"
#include "Movie.h"
//#include "Movie.h"
using std::string; using std::cout; using std::endl;

void MovieCollection::borrowMovie(Member & currentMember) {
    cin.ignore();
    string title = dataEntry("title of the movie you would like to borrow");
    Movie * movie = allMovies.findMovie(title);
    if (movie != nullptr) {
        if (movie->numAvailable > 0) {
            ++currentMember.moviesHeld[title];
            movie->numAvailable -= 1;
            movie->numTimesBorrowed += 1;
        } else {
            cout << "No copies of " << title <<" available." << endl;
        }               
    } else {
        cout << "Movie does not exist." << endl;
    }
}

void MovieCollection::displayAllMovies() {
    allMovies.inOrder();
}

void MovieCollection::addMovie() {
    cout << endl;
    cin.ignore();
    string title = dataEntry("movie title");
    // pointer to movie object in BST (null ptr if it does not exist)
    Movie * existingMovie = allMovies.findMovie(title);
    if (existingMovie != nullptr) { //if movie exists
        int numAddCopies = 0;
        cout << "How many copies would you like to add?: ";
        std::cin >> numAddCopies;
        existingMovie->numCopies += numAddCopies;
        existingMovie->numAvailable += numAddCopies;
        cout << "Added " <<numAddCopies << " new copies of "<< title <<". " << existingMovie->numCopies <<" copies in total."<< endl;

    } else {
        // retrieve information about the movie 
        string actors = dataEntry("starring actor(s)");
        string directors = dataEntry("director(s)");
        int genre = getGenre();
        int classification = getClassification();
        cout << endl; cin.ignore();
        string durS = dataEntry("duration (minutes)");
        string relDateS = dataEntry("release date (year)");
        string numCopS = dataEntry("number of copies available");
        cout << endl;
        int duration = std::stoi(durS);
        int releaseDate = std::stoi(relDateS);
        int numCopies = std::stoi(numCopS);
        //add movie to the BST
        allMovies.insertMovie( 
            Movie(title, actors, directors, genre, classification, duration,
            releaseDate, numCopies)
        );

    }
}

void MovieCollection::removeMovie() {
    cin.ignore();
    string title = dataEntry("title of the movie you would like remove");
    Movie * existingMovie = allMovies.findMovie(title);
    if (existingMovie == nullptr) {
        cout << "Movie not found. ";
    } else {
        cout << "There are currently " << existingMovie->numCopies << " copies of " << title <<"." <<endl;
        cout << "Enter the number of copies to remove: ";
        int numToRemove;
        cin >> numToRemove;
        if (numToRemove >= existingMovie->numCopies) {

        } else {
            existingMovie->numCopies -= numToRemove;
            existingMovie->numAvailable -= numToRemove;
             cout << "Removed " <<numToRemove << " copies of "<< title <<". There are now " << existingMovie->numCopies <<" copies in total."<< endl;
        }
    }
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