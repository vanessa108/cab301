#include<string.h>
#include<iostream>

#include "MovieCollection.h"
#include "Movie.h"
using std::string; using std::cout; using std::endl;

void MovieCollection::insertMovie(Movie newMovie, MovieNode * root) {
    if (root == NULL) {
        root->data = newMovie;
        root->left = NULL;
        root->right = NULL;
    } else {
        string currentTitle = root->data.title;
        string newTitle = newMovie.title;
        //int loopSize = std::max(currentTitle.size(), newTitle.size());
        int titleComparison = strcmpi(currentTitle.c_str(), newTitle.c_str());
        if (titleComparison < 0) {
            //put movie on right
            insertMovie(newMovie, root->right);
        } else if (titleComparison > 0) {
            //movie on right
            insertMovie(newMovie, root->left);
        } 

    }
}






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