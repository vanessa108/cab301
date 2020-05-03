#include<iostream>

#include "Movie.h"
#include "MovieCollection.h"
#include "MemberCollection.h"
#include "Member.h"
#include "Menu.h"

using std::cout; using std::endl; using std::cin;

bool videoStore = true; //program running
Menu menu; // initialise menu class
MemberCollection memberCol; //initialise member class
MovieCollection movieCol; //initialise movie class

void importData(); 

int main() {
    importData(); //import data
    cin.ignore();
    // video store modes, -1 = main menu, 1 = staff mode, 2 = member mode, 3 = exit video store
    int mode = -1;
    while (videoStore) {
        if (mode == 1) {
            if (!menu.staffAccess) {
                // retrieve and validate staff login
                menu.staffPassword(mode);
            } 
            while (menu.staffAccess) {
                // display and retrieve input from staff menu
                int staffMode = menu.staffMenu(mode);
                if (staffMode == 1) {
                    //movieCol.addMovie();
                    movieCol.root.data.displayInfo();
                } 
                if (staffMode == 2) {

                }
                if (staffMode == 3) {
                    memberCol.registerMember();
                } 

            }
           
        } else if (mode == 2) {
            // retrieve and validate member login
            if (!menu.memberAccess) {
                menu.memberPassword(mode, memberCol);
            }
            while (menu.memberAccess) {
                menu.memberMenu(mode);
            }
        //exit video store
        } else if (mode == 0) {
            cout << "Exiting video store";
            return 0;
        } else {
            mode = menu.mainMenu();
        }
    }   

}
 
void importData() {
    // Movie newMovie = Movie(
    //     "Movie 1", 
    //     "A1", "D1",
    //     1, 2, 
    //     100, 200, 4
    // );
    // movieCol.insertMovie(newMovie, &movieCol.root);

    memberCol.members[0] = Member(
        "Vanessa",
        "Li",
        "Address 1",
        "12345678",
        "1111"
    );
    memberCol.members[1] = Member(
        "Jarod",
        "Lam",
        "Address 2",
        "12345678",
        "1111"
    );

    memberCol.members[2] = Member(
        "Alan",
        "Yu",
        "Address 3",
        "12345678",
        "1111"
    );

    memberCol.members[3] = Member(
        "Riva",
        "Mendoza",
        "Address 4",
        "12345678",
        "1111"
    );


}

