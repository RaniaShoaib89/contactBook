
#pragma once
#define GROUP_H
#include <iostream>
#include <string>
#include "Contact.h"
#include "ResizableArray.h"
using namespace std;


class Group {
private:
    static int uniqueID;
    int groupID;
    string groupName;
   
    ResizableArray<Contact*> contacts;
    int capacity;
    int size_of_group;


public:

    void clearContacts();
    Group(std::string name = "", int capacity = 1);
    ~Group();
    void addContact(Contact& contact);
    void removeContact(Contact& contact);
    void printGroupContacts() const;
    void setGroupName(std::string name);
    std::string getGroupName() const;
    int getGroupID() const;
    bool operator==(const Group& other) const;
    ResizableArray<Contact*> getContacts() const;
  
    
};

