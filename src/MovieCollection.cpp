#include<string.h>
#include<iostream>

#include "MovieCollection.h"
#include "Movie.h"
#include "MemberCollection.h"
//#include "Movie.h"
using std::string; using std::cout; using std::endl;

/** Top 10 most borrowed function **/
void MovieCollection::mostBorrwowed() {
    //find number of movies in tree
    int numMovies = allMovies.treeSize();
        
    Movie movieArray[numMovies];

    //transfer movies from tree to movie array
    allMovies.treeToArray(movieArray);

    //apply quick sort 
    quickSort(movieArray, 0, numMovies-1);
    // list top 10 most borrowed
    cout << "Top 10 most borrowed movies:" << endl;
    // loop through sorted array from back to front/10th to back
    int i = 1; 
    while (i <= 10 and i <= numMovies) {
        Movie thisMovie = movieArray[numMovies - i];
        cout << i<< ": " << thisMovie.title << ".....borrowed " << thisMovie.numTimesBorrowed << " times." << endl; 
        i++;     
    }
}

void MovieCollection::borrowMovie(int currentMember, MemberCollection & memberCol) {
    cin.ignore();
    // prevent member from borrowing movie if they currently have 10
    if (memberCol.members[currentMember].moviesHeld.size() >= 10) {
        cout << "You currently have 10 movies borrowed. Please return a movie before borrowing another one." << endl;
        return;
    }
    string title = dataEntry("title of the movie you would like to borrow");
    Movie * movie = allMovies.findMovie(title); // check movie exists
    if (movie != nullptr) {
        if (movie->numAvailable > 0) {
            // if member already holds a copy of the movie
            if (memberCol.members[currentMember].moviesHeld.count(title) > 0) {
                cout << "You have already borrowed a copy of " << title << ". " << endl;
            } else {
                // add movie to member's list of borrowed movies
                memberCol.members[currentMember].moviesHeld.insert(title);
                movie->numAvailable -= 1; 
                movie->numTimesBorrowed += 1;
                cout << "You have borrowed a copy of " << title << ". " << endl;
            }
        } else { // no copies available
            cout << "No copies of " << title <<" available." << endl;
        }               
    } else { // movie title not found
        cout << "Movie does not exist." << endl;
    }
}

void MovieCollection::returnMovie(int currentMember, MemberCollection & memberCol) {
    cin.ignore();
    string title = dataEntry("title of the movie you would like to return");
    Member thisMember = memberCol.members[currentMember];
    // check member has movie borrowed
    if (thisMember.moviesHeld.count(title) > 0) {
        memberCol.members[currentMember].moviesHeld.erase(title);
        Movie * movie = allMovies.findMovie(title);
        movie-> numAvailable += 1;
        cout << "You have returned " << title << ". " << endl;
    } else {
        //member does not have any copies of movie
        cout << "You have no copies of " << title << " withheld." << endl;
    }

}

void MovieCollection::displayAllMovies() {
    // in order traversal to display movies in alphabetical order
    allMovies.inOrder();
}

void MovieCollection::addMovie() {
    cout << endl << "You are adding a movie to the library." << endl;
    cin.ignore();
    string title = dataEntry("movie title");
    // pointer to movie object in BST (null ptr if it does not exist)
    Movie * existingMovie = allMovies.findMovie(title);
    if (existingMovie != nullptr) { //if movie exists
        int numAddCopies = 0;
        cout << "How many copies would you like to add?: ";
        // increase number of copies
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
            releaseDate, numCopies, 0) // numTimesBorrowed = 0
        );
        cout << "You have successfully added " << title << " to the library." << endl;

    }
}

void MovieCollection::removeMovie() {
    cin.ignore();
    string title = dataEntry("title of the movie you would like remove");
    Movie * existingMovie = allMovies.findMovie(title);
    // if the movie does not exist
    if (existingMovie == nullptr) {
        cout << "Movie not found. ";
    } else {
        cout << "There are currently " << existingMovie->numCopies << " copies of " << title <<"." <<endl;
        cout << "Enter the number of copies to remove: ";
        int numToRemove;
        cin >> numToRemove;
        // if the number of movies to remove is more than the number of existing copies 
        if (numToRemove >= existingMovie->numCopies) {
            cout << "You are trying to remove all copies of " <<title << ". " << endl;
            cout << "Select 1 to delete the entire movie from the library, or 2 to only remove the copies." << endl;
            int option;
            cin >> option;
            // remove movie from library (delete node from BST)
            if (option == 1) {
                //allMovies.preOrder();
                allMovies.deleteMovie(title);
                //allMovies.preOrder();
                cout << title << " has been removed from the movie library." << endl;
            } 
            // decrease number of copies but keep movie in BST
            else {
                existingMovie->numCopies = 0;
                existingMovie->numAvailable = 0;
                cout << "Removed " <<numToRemove << " copies of "<< title <<". There are now 0 copies in total."<< endl;
            }
        } else {
            //decrease number of copies based of number to remove
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
    // check user input is a number
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
    // check option is a number
    if (isdigit(input)) {
        return input;
    } else {
        return 10;
    }
}
// input: pointer to first item in movie array, left array and right array
void MovieCollection::quickSort(Movie * movies, int l, int r) {
    if (l < r) {
        int s = partition(movies, l, r);
        //create new subarrays, either side of the pivot
        quickSort(movies, l, s);
        quickSort(movies, s+1, r);
    }
}

// Based of Hoare's paritioning
int MovieCollection::partition(Movie * movies, int l, int r) {
    int p = (movies + l)->numTimesBorrowed; // value of pivot
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
// helper function to swap 
void MovieCollection::swap(Movie *a, Movie *b) {
        Movie temp = *a;
        *a = *b;
        *b = temp;
}