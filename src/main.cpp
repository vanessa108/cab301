#include<iostream>

#include "Movie.h"
#include "MovieCollection.h"
#include "MemberCollection.h"
#include "Member.h"
#include "Menu.h"

using std::cout; using std::endl; using std::cin;

bool videoStore = true;;
Menu menu;
MemberCollection memberCol;

void importData();

int main() {
    importData();
    cin.ignore();
    int mode = -1;
    while (videoStore) {

        if (mode == 1) {
            if (!menu.staffAccess) {
                menu.staffPassword(mode);
            } 
            while (menu.staffAccess) {
                int staffMode = menu.staffMenu(mode);
                if (staffMode == 3) {
                    memberCol.registerMember();
                }

            }
           
        } else if (mode == 2) {
            if (!menu.memberAccess) {
                menu.memberPassword(mode, memberCol);
            }
            while (menu.memberAccess) {
                menu.memberMenu(mode);
            }
        } else if (mode == 0) {
            cout << "Exiting video store";
            return 0;
        } else {
            mode = menu.mainMenu();
        }
    }   

}
 
void importData() {
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


}

