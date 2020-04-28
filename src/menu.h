#ifndef MENU_H
#define MENU_H

#include<iostream>
#include "MemberCollection.h"

class Menu {
public:
    int mainMenu();

    int staffMenu(int &mode);
    void staffPassword(int &mode);
    bool staffAccess = false;

    void memberMenu(int & mode);
    void memberPassword(int &mode, MemberCollection &memberCol);
    bool memberAccess = false; 
    
private:

};

#endif