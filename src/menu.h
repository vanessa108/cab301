#ifndef MENU_H
#define MENU_H

#include<iostream>
#include "MemberCollection.h"
#include "Member.h"


class Menu {
public:
    int mainMenu();

    int staffMenu(int &mode);
    
    /* Checks staff log in */
    void staffPassword(int &mode);
    /* StaffAccess stays true until staff member returns to main menu */
    bool staffAccess = false; 
    
    int memberMenu(int & mode);

    /* Checks member log in */
    void memberPassword(int &mode, MemberCollection &memberCol, Member &currentMember);
    
    /* StaffAccess stays true until staff member returns to main menu */
    bool memberAccess = false; 
    
private:

};

#endif