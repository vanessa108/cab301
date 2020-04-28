#ifndef MEMBER_h
#define MEMBER_h

#include <map>
#include <string.h>
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::string;

class Member {
public:
    Member(string _lastName, string _firstName, string _address, string _phoneNum, string _pwd) 
        : lastName{_lastName}, firstName{_firstName}, address{_address}, phoneNum{_phoneNum}, pwd{_pwd} {}
        
    //data strcture with information about all movies the member is holding
    // key with movie name, size_t with number of copies held
    std::map<string, size_t> moviesHeld;
    //string customerID;
    string lastName;
    string firstName;
    string address;
    string phoneNum;
    string pwd;
    
    
    
};







#endif