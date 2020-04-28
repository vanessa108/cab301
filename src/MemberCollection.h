#ifndef MEMBERCOLLECTION_H
#define MEMBERCOLLECTION_H

#include <string.h>
#include <iostream>
#include "Member.h"

using std::cout; using std::endl; using std::cin; using std::string;

class MemberCollection {
public:
    //array of members
    //Member members[15];


    void registerMember();
    void findMemberPhone();
    void borrowMovie();
    void returnMovie();
    void listMemberMovies();

private:
    int totalMembers = 0; //number of members registered in the system
    string dataEntry(string dataName);
    bool passwordValidation(string pwd);

};







#endif