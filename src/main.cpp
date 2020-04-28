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

int main() {
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
                menu.memberPassword(mode);
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
 


