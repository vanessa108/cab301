#include "MemberCollection.h"
#include <string.h>
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::string;

void MemberCollection::registerMember() {
    cin.ignore();
    string firstName = dataEntry("first name");
    string lastName = dataEntry("last name");
    //check duplicate
    for (int i = 0; i < totalMembers; i++) {
        if (members[i].firstName == firstName and members[i].lastName == lastName) {
            cout << firstName << " " << lastName << " has already registered." << endl;
            return;
        }
    }
    string address = dataEntry("address");
    string phNum = dataEntry("phone number");
    string pwd = dataEntry("password (4 digits)");
    while (!passwordValidation(pwd)) {
        cout << "Password invalid, must be 4 digits." << endl;
        pwd = dataEntry("password (4 digits)");
    }
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
    bool allDigit = false;
    for (auto c : pwd) {
        if (!isdigit(c)) {
            break;
        }
        allDigit = true;
    }
    if (allDigit and pwd.size() == 4) {
        return true;
    } else {
        return false;
    }
}