#include "Contact.h"
#include "Address.h"
#include <string>
#include <iostream>
#include <algorithm>

Contact::Contact(std::string first_name = "", std::string last_name = "", std::string mobile_number = "", std::string email_address ="", Address* address = nullptr) :first_name(first_name), last_name(last_name),
mobile_number(mobile_number), email_address(email_address),  address(address) {
	if (address) {
		this->address = new Address(*address);
	}
};

Contact::Contact() : first_name(""), last_name(""), mobile_number(""), email_address(""), address(nullptr){}

Contact::Contact(const Contact& obj)
	: first_name(obj.first_name), last_name(obj.last_name), mobile_number(obj.mobile_number), email_address(obj.email_address), address(nullptr) {
	try {
		if (obj.address) {
			address = new Address(*obj.address);
		}
	}
	catch (...) {
		delete address;
		throw;
	}
}

Contact& Contact::operator=(const Contact& obj) {
	if (this != &obj) {
		first_name = obj.first_name;
		last_name = obj.last_name;
		mobile_number = obj.mobile_number;
		email_address = obj.email_address;

		try {
			Address* new_address = nullptr;
			if (obj.address) {
				new_address = new Address(*obj.address);
			}
			delete address;
			address = new_address;
		}
		catch (...) {
			delete address;
			throw;
		}
	}
	return *this;
}

void Contact::setFirstName(string x) { first_name = x; };
void Contact::setLastName(string x) { last_name = x; };
void Contact::setMobileNumber(string x) { mobile_number = x; };
void Contact::setEmailAddress(string x) { email_address = x; };
void Contact::setAddress(string house, string street, string city, string country) {
	
	this->address->setHouse(house);
	this->address->setStreet(street);
	this->address->setCity(city);
	this->address->setCountry(country);
}
string Contact::getFirstName() const { return first_name; } ;
string Contact::getLastName() const { return last_name; };
string Contact::getMobileNumber() const { return mobile_number; };
string Contact::getEmailAddress() const { return email_address; };
Address* Contact::getAddress() const { return address;};
bool Contact::matchesString(const string& str) const {
	string concatenated_str = first_name + " " + last_name + " " +
		mobile_number + " " + email_address + " " +
		address->getHouse() + " " + address->getStreet() +
		" " + address->getCity() + " " + address->getCountry();

	string lowercase_concatenated = concatenated_str;
	transform(lowercase_concatenated.begin(), lowercase_concatenated.end(), lowercase_concatenated.begin(), ::tolower);

	string lowercase_query = str;
	transform(lowercase_query.begin(), lowercase_query.end(), lowercase_query.begin(), ::tolower);


	size_t index = 0;
	for (char ch : lowercase_concatenated) {
		if (ch == lowercase_query[index]) {
			index++;
			if (index == lowercase_query.size()) {
				
				return true;
			}
		}
	}

	 cout<< "No match found" << endl;
	return false;
}




/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/
bool Contact::equals(Contact& contact)
{
	
	if (this->first_name == contact.first_name && this->last_name == contact.last_name /*&& this->mobile_number == contact.mobile_number*/ &&
		this->email_address == contact.email_address && this->address->equals(*(contact.address)))
	{
		
		return true;
		
	}
	else
	{
		return false;
	}
}


Contact* Contact::copy_contact() const
{
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
	Address* copy_address = nullptr;
	if (address) {
		copy_address = new Address(address->getHouse(), address->getStreet(), address->getCity(), address->getCountry());
	}
	
	Contact* copy_contact = new Contact(first_name, last_name, mobile_number, email_address, copy_address);
	return copy_contact;

}

istream& operator>>(istream& in, Contact& contact) {
	cout << "Enter first name: ";
	getline(cin >> ws, contact.first_name); 
	cout << "Enter last name: ";
	getline(cin >> ws, contact.last_name); 
	

	bool validPhoneNumber = false;
	while (!validPhoneNumber) {
		cout << "Enter phone number (exactly 11 digits): "; 
		getline(cin >> ws, contact.mobile_number); 

		if (contact.mobile_number.length() == 11 &&
			all_of(contact.mobile_number.begin(), contact.mobile_number.end(), ::isdigit))
		{
			validPhoneNumber = true;
		}
		else
		{
			cout << "Invalid phone number.\nEnter exactly 11 digits." << endl;
		}
	}
	bool validEmail = false;
	while (!validEmail) {
		cout << "Enter Email Address: ";
		getline(cin >> ws, contact.email_address); 

		
		if (contact.email_address.find('@') != string::npos) {
			validEmail = true;
		}
		else {
			cout << "Invalid email address.\nMust include '@' in email address." << endl;
		}
	}


	
	contact.address = new Address(); 
	in >> *(contact.address);
	return in;
}

void Contact::printDetails() const
{
	cout << "print function called " << endl;
	cout << "Name: " << getFirstName() << " " << getLastName() << " Mobile Number: " << getMobileNumber() << " Email Address: "
		<< getEmailAddress() << endl;
	cout << "Address Details: ";

	Address* addressPtr = getAddress();
	if (addressPtr) {
		addressPtr->print_address();
	}
	else {
		cout << "No address available." << endl;
	}

	cout << endl;
}
Contact::~Contact() {
	delete address;
}

bool Contact::operator==(const Contact& obj) const {
	if (this == &obj) {
		return true;
	}

	return first_name == obj.first_name &&
		last_name == obj.last_name &&
		mobile_number == obj.mobile_number &&
		email_address == obj.email_address &&
		(*address) == (*obj.address);
}