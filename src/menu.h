#ifndef MENU_H
#define MENU_H

#include<iostream>
#include "MemberCollection.h"

class Menu {
public:
    int mainMenu();

    int staffMenu(int &mode);
    //validates staff menu
    void staffPassword(int &mode);
    // When staff logs in, staff access is true until staff returns to main menu
    bool staffAccess = false; 

    //validates member password 
    void memberMenu(int & mode);
    void memberPassword(int &mode, MemberCollection &memberCol);
    // When member logs in, member access is true until member returns to main menu
    bool memberAccess = false; 
    
private:

};

#endif