#include<iostream>

#include "Movie.h"
#include "MovieCollection.h"
#include "MemberCollection.h"
#include "Member.h"
#include "Menu.h"

using std::cout; using std::endl; using std::cin;

bool videoStore = true; //program running

/** Contains all menu functions, manages inputs **/
Menu menu; // initialise menu class
/** Contains array of member objects **/
MemberCollection memberCol; //initialise member class
/** Contains BST of movie nodes **/
MovieCollection movieCol; //initialise movie class

void importData(); 

int main() {
    cout << "Importing sample data... press enter to continue";
    importData(); //import sample data
    cout << endl;
    cin.ignore();
    // video store modes, -1 = main menu, 1 = staff mode, 2 = member mode, 3 = exit video store
    int mode = -1;
    while (videoStore) {

        /******************************************
         *         Staff menu functionality 
         * ****************************************/
        if (mode == 1) {
            if (!menu.staffAccess) {
                // retrieve and validate staff login
                menu.staffPassword(mode);
            } 
            while (menu.staffAccess) {
                // display and retrieve input from staff menu
                int staffMode = menu.staffMenu(mode);
                if (staffMode == 1) {
                    movieCol.addMovie();
                } 
                if (staffMode == 2) {
                    //display all movies in alphabetical order
                    movieCol.removeMovie();
                }
                if (staffMode == 3) {
                    memberCol.registerMember();
                } 
                if (staffMode == 4) {
                    memberCol.findMemberPhone();
                }
            }
         /******************************************
         *         Member menu functionality 
         * ****************************************/         
        
        } else if (mode == 2) {
            int currentMember; //index to current member's position in member array
            // retrieve and validate member login
            if (!menu.memberAccess) {
                menu.memberPassword(mode, memberCol, currentMember);
            } 
            // while member has not left member menu
            while (menu.memberAccess) {
                int memberMode = menu.memberMenu(mode);
                if (memberMode == 1) {
                    movieCol.displayAllMovies();
                }
                if (memberMode == 2) {
                    movieCol.borrowMovie(currentMember, memberCol);
                }
                if (memberMode == 3) {
                    movieCol.returnMovie(currentMember, memberCol);
                }
                if (memberMode == 4) {
                    memberCol.listMemberMovies(currentMember);
                }
                if (memberMode == 5) {
                    movieCol.mostBorrwowed();
                }
            }

        /** exit video store **/
        } else if (mode == 0) {
            cout << "Exiting video store";
            return 0;
        } else {
            mode = menu.mainMenu();
        }
    }   

}
 
/** Test data used for testing functionality**/
void importData() {
    movieCol.allMovies.insertMovie(Movie(
        "Movie 1", 
        "Actor 1", "Director 1",
        1, 2, 
        120, 2001, 4, 2
    ));


    movieCol.allMovies.insertMovie(Movie(
        "Movie 2", 
        "Actor 2", "Director 2",
        1, 2, 
        70, 2019, 4, 3
    ));

    movieCol.allMovies.insertMovie(Movie(
        "Movie 3", 
        "Actor 3", "Director 3",
        1, 2, 
        100, 2019, 4, 2
    ));

    movieCol.allMovies.insertMovie(Movie(
        "A Very Interesting Movie", 
        "Actor", "D1",
        1, 2, 
        60, 2020, 4, 1
    ));

    movieCol.allMovies.insertMovie(Movie(
        "Mulan", 
        "Ming-Na Wen", "Tony Bancroft, Barry Cook",
        1, 2, 
        87, 1998, 4, 2
    ));

    movieCol.allMovies.insertMovie(Movie(
        "Aladdin", 
        "Will  Smith, Mena Massoud", "Guy Ritchie",
        1, 2, 
        128, 2019, 1, 2
    ));

    movieCol.allMovies.insertMovie(Movie(
        "Tangled", 
        "Mandy Moore, Zachary Levi", "Byron Howard, Nathan Greno",
        1, 2, 
        100, 2010, 4, 9
    ));

    memberCol.members[0] = Member(
        "Vanessa",
        "Li",
        "Address 1",
        "12345678",
        "1111"
    );

}

