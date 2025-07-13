#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;
	

	

public:

	string phone[5] = {};
	void setFirstName(string);
	void setLastName(string);
	void setMobileNumber(string);
	void setEmailAddress(string);
	void setAddress(string, string, string, string);
	//int getId() { return contactid };

	string getFirstName() const;
	string getLastName() const;
	string getMobileNumber()const;
	string getEmailAddress() const;
	Address* getAddress() const;
	friend istream& operator>>(istream& in, Contact& contact);
	Contact& operator=(const Contact& obj);
	Contact(const Contact& obj);
	bool matchesString(const string& str) const;
	void printDetails() const;
	bool equals(Contact& contact);
	Contact* copy_contact() const;
	Contact();
	~Contact();
	bool operator==(const Contact& other) const;
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
};

