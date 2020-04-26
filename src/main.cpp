#include<iostream>

#include "Movie.h"
#include "MovieCollection.h"
#include "MemberCollection.h"
#include "Member.h"
#include "menu.h"

using std::cout; using std::endl; using std::cin;

int main() {
    int mode = -1;
    while (mode == -1) {
        int something = mainMenu();
        cout << something;
    }

}


int mainMenu(){
    cout << "===========Main Menu===========" << endl;
    cout << "1. Staff Login" << endl;
    cout << "2. Member Login" << endl;
    cout << "0. Exit" << endl;
    cout << "===============================" << endl;
    cout << "Please make a selection (1-2, 0 or exit):"<<endl;
    char input = 0;
    cin>>input;
    switch(input) {
        case '1':
            return 1;
        case '2':
            return 2;
        case '0':
            return 0;
        default:
            cout << input << " is invalid, select an input 1-2 or 0 to exit:" << endl;
            return -1;
    }
}