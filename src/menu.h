#ifndef MENU_H
#define MENU_H

#include<iostream>

class Menu {
public:
    int mainMenu();

    void staffMenu(int &mode);
    void staffPassword(int &mode);
    bool staffAccess = false;

    void memberMenu(int & mode);
    void memberPassword(int &mode);
    bool memberAccess = false; 
    
private:

};

#endif