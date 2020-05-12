#ifndef MEMBER_h
#define MEMBER_h

#include <set>
#include <string.h>
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::string;

/* Represents a member */ 
class Member {
public:
    /* default initialiser */
    Member() {

    }
    /* intialises with values when a member is registered */
    Member(string _firstName, string _lastName, string _address, string _phoneNum, string _pwd) 
        :lastName{_lastName}, 
        firstName{_firstName}, 
        address{_address}, 
        phoneNum{_phoneNum}, 
        pwd{_pwd} 
        {
        }
        
    //data strcture with information about all movies the member is holding
    // key with movie name, size_t with number of copies held
    std::set<string> moviesHeld;
    string lastName;
    string firstName;
    string address;
    string phoneNum;
    string pwd;
    
    
    
};







#endif