#include "Menu.h"
#include<iostream>
#include<string.h>
#include<cctype>

using std::cout; using std::endl; using std::cin; using std::string;

int Menu::mainMenu(){
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

void Menu::staffPassword(int &mode) {
    string username;
    string password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;
    if (username == "staff" and password == "today123") {
        staffAccess = true;
    } else {
        cout << "Username or password incorrect, select 1 to try again or 0 to return to the main menu" << endl;
        int input; cin >> input;
        if (input == 0) {
            mode = -1;
        } else if (input == 1){
            staffPassword(mode);
        }   
    }
}

void Menu::staffMenu(int &mode){

    cout << "\n===========Staff Menu===========" << endl;
    cout << "1. Add a new movie DVD" << endl;
    cout << "2. Remove a movie DVD" << endl;
    cout << "3. Register a new Member" << endl;
    cout << "4. Find a registered member's phone number" << endl;
    cout << "0. Return to main menu" << endl;
    cout << "================================" << endl;
    cout << "Please make a selection (1-4, 0 or return to main menu):"<<endl;
    char input = 0;
    cin>>input;
    switch(input) {
        case '1':
            break;
        case '2':
            //return 2;
            break;
        case '3':
            //return 2;
            break;
        case '4':
            //return 2;
            break;
        case '0':
            staffAccess = false;
            mode = -1;
            break;
        default:
            cout << input << " is invalid, select an input 1-4 or 0 to exit:" << endl;
            break;
            //return -1;
    }
}

void Menu::memberPassword(int &mode) {
    string username; string password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;
    string firstName; string lastName;
    int caps; //find capital letter to split username into first and last name
    for (int i = 1; i < username.size(); i++) {
        if (isupper(username[i])) {
            caps = i;
            break;
        }
    }
    lastName = username.substr(0, caps);
    firstName = username.substr(caps); 
    if ((firstName == "Vanessa" and lastName == "Li") and password == "1111") {
        memberAccess = true;
    } else {
        cout << "Username or password incorrect, select 1 to try again or 0 to return to the main menu" << endl;
        int input; cin >> input;
        if (input == 0) {
            mode = -1;
        } else if (input == 1){
            memberPassword(mode);
        }   
    }

}

void Menu::memberMenu(int &mode){

    cout << "\n=========Member Menu==========" << endl;
    cout << "1. Display all movies" << endl;
    cout << "2. Borrow a movie DVD" << endl;
    cout << "3. Return a movie DVD" << endl;
    cout << "4. List current borrowed movie DVDs" << endl;
    cout << "5. Display top 10 most popular movies" << endl;
    cout << "0. Return to main menu" << endl;
    cout << "================================" << endl;
    cout << "Please make a selection (1-4, 0 or return to main menu):"<<endl;
    char input = 0;
    cin>>input;
    switch(input) {
        case '1':
            break;
        case '2':
            //return 2;
            break;
        case '3':
            //return 2;
            break;
        case '4':
            //return 2;
            break;
        case '5':
            //return 2;
            break;
        case '0':
            memberAccess = false;
            mode = -1;
            break;
        default:
            cout << input << " is invalid, select an input 1-4 or 0 to exit:" << endl;
            break;
            //return -1;
    }
}