#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	friend istream& operator>>(istream& in, Address& address);
	bool equals(const Address& address);
	void print_address();
	Address copy_address();
	string getStreet();
	string getHouse();
	string getCountry();
	string getCity();
	void setStreet(string x);
	void setHouse(string x);
	void setCountry(string x);
	void setCity(string x);
	Address(std::string= "", std::string = "", std::string = "", std::string ="");
	bool operator==(const Address& other) const;
	~Address() { };
	string toString() const;
};


