#ifndef MEMBERCOLLECTION_H
#define MEMBERCOLLECTION_H

#include <string.h>
#include <iostream>
#include "Member.h"

using std::cout; using std::endl; using std::cin; using std::string;

/* Represents a collection of members */
class MemberCollection {
public:
    /* Array of members */ 
    Member members[15]; 
    /* total number of members, used to index the array */    
    int totalMembers = 5; 

    /* Retrieves member information and inputs member object in a member array */
    void registerMember();

    /* Validates a members login details 
    *   Output: true if username/password matches */
    bool checkMemberPassword(string username, string password, int &currentMember);

    int findMember(string firstname, string lastname);
    
    /* List the title and number of copies of movies held by a member
    *    Input: reference to member location */
    void listMemberMovies(int currentMember);
    
    void findMemberPhone();

private:
    /** Helper function for cout/cin data entries
    *   Input: string containing name of what data is being retrieved
    *   Returns string with the user's input **/
    string dataEntry(string dataName);

    /* Data validation for the initial user password
     *  Input: string of provided password
     *  Output: true is password is 4 digits */
    bool passwordValidation(string pwd);

};







#endif