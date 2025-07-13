#pragma once
#define CONTACTSBOOK_H
#include "Address.h"
#include "Contact.h"
#include "Group.h"
#include "HistoryObject.h"
#include <algorithm>
#include "ResizableArray.h"
#include <iostream>
#include <string>
#include <vector>

//#ifndef BASIC_LIB
//#define BASIC_LIB
//#include <iostream>
//#include <string>
//#endif // !BASIC_LIB




class Group;

class ContactsBook {
private:
	Contact* contacts_list; 
	int size_of_contacts;  
	int contacts_count;     
	ResizableArray<Group*> groups;
	HistoryObject history;
	vector<string> search_history;
	
public:
	void add_contact(const Contact& contact);
	int total_contacts() const;

	Contact* search_contact(const std::string first_name, const std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);

	ContactsBook(int size_of_list);
	ContactsBook();
	ContactsBook& operator=(const ContactsBook& obj);
	Contact* copy_contacts_list() const;
	void print_contacts_sorted(std::string choice); 
	void merge_duplicates(); 
	void view_contact_details() const;
	void update_contact();
	void delete_contact();
	void search_advance(const string& str);
	vector<string> get_top_5_searches() const;
	
	
	

/*
*  This function loads contacts from the given file (see details in ContactsBook.cpp)
*/
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);
	friend istream& operator>>(istream& in, ContactsBook& contactsbook);
	~ContactsBook();
	void print_unsorted() const;
	ContactsBook& operator+=(const ContactsBook& obj);

	//////group functions listed below
	void createGroup(const string& groupName);
	void deleteGroup(const string &groupName);
	void addContactToGroup(const string& groupName, int index);
	void displayGroups() const;
	void deleteContactFromGroup(const std::string& groupName, int index);

	
	
	

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, std::string choice);
};

