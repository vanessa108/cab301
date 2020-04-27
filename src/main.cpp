#include<iostream>

#include "Movie.h"
#include "MovieCollection.h"
#include "MemberCollection.h"
#include "Member.h"
#include "Menu.h"

using std::cout; using std::endl; using std::cin;

bool videoStore = true;;
Menu menu;

int main() {
    int mode = -1;
    while (videoStore) {

        if (mode == 1) {
            if (!menu.staffAccess) {
                menu.staffPassword(mode);
            } 
            while (menu.staffAccess) {
                menu.staffMenu(mode);
            }
           
        } else if (mode == 2) {

        } else if (mode == 0) {
            cout << "Exiting video store";
            return 0;
        } else {
            mode = menu.mainMenu();
        }
    }   

}



