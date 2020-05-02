#ifndef MEMBERCOLLECTION_H
#define MEMBERCOLLECTION_H

#include <string.h>
#include <iostream>
#include "Member.h"

using std::cout; using std::endl; using std::cin; using std::string;

class MemberCollection {
public:
    
    Member members[15];     //array of members
    int totalMembers = 4;   //total number of members stored, used for indexing array

    // registers a new member and adds to member collection
    void registerMember();
    // Validate a member's login details
    bool checkMemberPassword(string username, string password);

    // not implemented
    void findMemberPhone();
    void borrowMovie();
    void returnMovie();
    void listMemberMovies();
    

private:
    // requests user input and returns string
    string dataEntry(string dataName);
    // checks that a new member's passowrd is valid (has 4 digits)
    bool passwordValidation(string pwd);

};







#endif