#include<string.h>
#include<iostream>

#include "MovieCollection.h"
#include "Movie.h"
//#include "Movie.h"
using std::string; using std::cout; using std::endl;

void MovieCollection::mostBorrwowed() {
    allMovies.treeToArray(movieArray);
    int numMovies = allMovies.treeSize();
    Movie sortedMovies[numMovies];
    for (int i = 0; i < numMovies; i++) {
        sortedMovies[i] = movieArray[i];
    }
    quickSort(sortedMovies, 0, numMovies-1);
    cout << "Top 10 most borrowed movies:" << endl;
    for (int i = numMovies-1; i >= 0; i--) {
        Movie thisMovie = sortedMovies[i];
        cout << thisMovie.title << ", borrowed " << thisMovie.numTimesBorrowed << " times." << endl;
    }
}

void MovieCollection::borrowMovie(Member & currentMember) {
    cin.ignore();
    string title = dataEntry("title of the movie you would like to borrow");
    Movie * movie = allMovies.findMovie(title);
    if (movie != nullptr) {
        if (movie->numAvailable > 0) {
            currentMember.moviesHeld.insert(title);
            movie->numAvailable -= 1;
            movie->numTimesBorrowed += 1;
            cout << "You have borrowed a copy of " << title << ". " << endl;
        } else {
            cout << "No copies of " << title <<" available." << endl;
        }               
    } else {
        cout << "Movie does not exist." << endl;
    }
}

void MovieCollection::returnMovie(Member & currentMember) {
    cin.ignore();
    string title = dataEntry("title of the movie you would like to return");
    if (currentMember.moviesHeld.count(title) > 0) {
        currentMember.moviesHeld.erase(title);
        Movie * movie = allMovies.findMovie(title);
        movie-> numAvailable += 1;
        cout << "You have returned " << title << ". " << endl;
    } else {
        cout << "You have no copies of " << title << " withheld." << endl;
    }

}

void MovieCollection::displayAllMovies() {
    // in order traversal to display movies in alphabetical order
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
            releaseDate, numCopies, 0)
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
    cout << "1. General (G) \n2. Parental Guidance (PG) \n3. Mature (M) \n4. Mature Accompanied (MA15+)" << endl;
    cout << "Make selection (1-4): ";
    cin>>input;
    if (isdigit(input)) {
        return input;
    } else {
        return 10;
    }
}

void MovieCollection::quickSort(Movie * movies, int l, int r) {
    if (l < r) {
        int s = partition(movies, l, r);
        quickSort(movies, l, s);
        quickSort(movies, s+1, r);
    }
}

int MovieCollection::partition(Movie * movies, int l, int r) {
    int p = (movies + l)->numTimesBorrowed;
    int i = l-1;
    int j = r+1;

    while (true) {
        do {
            i++;
        } while ((movies + i)->numTimesBorrowed < p );

        do {
            j--;
        } while ((movies + j)->numTimesBorrowed > p);

        if (i >= j) {
            break;
        } 
        swap((movies+i), (movies+j));
    }
    swap((movies+l), (movies+j));
    return j;
}

void MovieCollection::swap(Movie *a, Movie *b) {
        Movie temp = *a;
        *a = *b;
        *b = temp;
}