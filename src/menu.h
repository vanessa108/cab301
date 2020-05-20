#ifndef MENU_H
#define MENU_H

#include<iostream>
#include "MemberCollection.h"
#include "Member.h"


class Menu {
public:
    /** displays text for main menu and retrieves user input
     * output: menu mode chosen */
    int mainMenu();

    /** displays text for staff menu and retrieves user input
     * output: menu mode chosen */
    int staffMenu(int &mode);
    
    /* Checks staff log in */
    void staffPassword(int &mode);

    /* StaffAccess stays true until staff member returns to main menu */
    bool staffAccess = false; 

    /** displays text for member menu and retrieves user input
     * output: menu mode chosen */
    int memberMenu(int & mode);

    /* Checks member log in */
    void memberPassword(int &mode, MemberCollection &memberCol, int &currentMember);
    
    /* StaffAccess stays true until staff member returns to main menu */
    bool memberAccess = false; 
    
private:

};

#endif