#include "MemberCollection.h"
#include "Member.h"
#include <string.h>
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::string;

Member * MemberCollection::findMember(string firstName, string lastName) {
    for (int i = 0; i < totalMembers; i++) {
        Member &registeredMem = members[i];
        if (firstName == registeredMem.firstName and lastName == registeredMem.lastName) {
            Member * pointerToMember = &registeredMem;
            return pointerToMember;
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

void MemberCollection::registerMember() {
    cin.ignore();
    string firstName = dataEntry("first name");
    string lastName = dataEntry("last name");
    //check duplicate using sequential search
    for (int i = 0; i < totalMembers; i++) {
        if (members[i].firstName == firstName and members[i].lastName == lastName) {
            cout << firstName << " " << lastName << " has already registered." << endl;
            return;
        }
    }
    string address = dataEntry("address");
    string phNum = dataEntry("phone number");
    string pwd = dataEntry("password (4 digits)");
    //ensure that password is 4 digits
    while (!passwordValidation(pwd)) {
        cout << "Password invalid, must be 4 digits." << endl;
        pwd = dataEntry("password (4 digits)"); //continue calling until valid password is provided
    }
    //initialise member in member collection
    members[totalMembers] = Member(firstName, lastName, address, phNum, pwd);
    totalMembers += 1;
    cout << "Sucessfully added " << firstName <<" "<< lastName << endl;
    

}

string MemberCollection::dataEntry(string dataName) {
    string input;
    cout << "Enter member's " + dataName + ": ";
    getline(cin, input);
    return input; 
}

bool MemberCollection::passwordValidation(string pwd) {
    bool allDigit = false; //true if all characters are digits
    for (auto c : pwd) {
        if (!isdigit(c)) {
            break;
        }
        allDigit = true;
    }
    if (allDigit and pwd.size() == 4) { //check there are only 4 digits
        return true; //password is valid
    } else {
        return false;
    }
}

bool MemberCollection::checkMemberPassword(string username, string password) {
    /** Split username into first name and last name **/
    string firstName; string lastName;
    int caps; //find capital letter to split username into first and last name
    for (int i = 1; i < username.size(); i++) {
        if (isupper(username[i])) {
            caps = i;
            break;
        }
    }
    lastName = username.substr(0, caps);
    firstName = username.substr(caps); 

    Member * existingMember = findMember(firstName, lastName);

    if (existingMember != nullptr) {
        if (existingMember->pwd == password) {
            return true;
        } else {
            cout << existingMember->pwd << endl;
            cout << "Incorrect password, ";
            return false;
        }
    }
    cout << "Invalid username, ";
    return false;
}