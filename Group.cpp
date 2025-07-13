#include "Group.h"
#include "Contact.h"
#include <iostream>
#include <string>

int Group::uniqueID = 1;

Group::Group(  string name, int capacity)
    : groupName(name), capacity(capacity), size_of_group(0), groupID(uniqueID++) {
}

Group::~Group() {
    clearContacts();
}

void Group::clearContacts() {
    for (int i = 0; i < size_of_group; ++i) {
        delete contacts.getArray()[i];
        contacts.getArray()[i] = nullptr;
    }
    size_of_group = 0;
}

void Group::addContact(Contact& contact) {
   
        contacts.addItem(&contact);

        ++size_of_group;
          cout << "Contact added to the group." <<   endl;
    
    
}

void Group::removeContact(Contact& contact) {
   
            contacts.removeItem(&contact);
            --size_of_group;

              cout << "Contact removed from the group." <<   endl;
            return;
      
      cout << "Contact not found in the group." <<   endl;
}

void Group::printGroupContacts() const {
      cout << "Group Name: " << groupName <<   endl;
      cout << "Group ID: " << groupID <<   endl;
    for (int i = 0; i < size_of_group; ++i) {
          cout << "Contact " << i + 1 << ":" <<   endl;
        if (contacts.getArray()[i] != nullptr) {
            contacts.getArray()[i]->printDetails();
           
            cout << endl;

  

       
         
        }
    }
}

void Group::setGroupName(  string name) {
    groupName = name;
}

  string Group::getGroupName() const {
    return groupName;
}

int Group::getGroupID() const {
    return groupID;
}

bool Group::operator==(const Group& other) const {
    return this->groupName == other.groupName && this->groupID == other.groupID;
}



ResizableArray<Contact*> Group::getContacts() const {
    return contacts;
}