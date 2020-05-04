#ifndef MENU_H
#define MENU_H

#include<iostream>
#include "MemberCollection.h"


class Menu {
public:
    int mainMenu();

    int staffMenu(int &mode);
    
    /* Checks staff log in */
    void staffPassword(int &mode);
    /* StaffAccess stays true until staff member returns to main menu */
    bool staffAccess = false; 
    
    void memberMenu(int & mode);

    /* Checks member log in */
    void memberPassword(int &mode, MemberCollection &memberCol);
    
    /* StaffAccess stays true until staff member returns to main menu */
    bool memberAccess = false; 
    
private:

};

#endif