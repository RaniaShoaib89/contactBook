#include "Address.h"
#include <iostream>
#include <string>


Address::Address(std::string house , std::string street , std::string city , std::string country ) : house(house),
street(street), city(city), country(country) {};





string Address::getStreet() { return street; };
string Address::getHouse() { return house; };
string Address::getCountry() { return country; };
string Address::getCity() { return city; };
void Address::setStreet(string x) { street = x; };
void Address::setHouse(string x) { house = x; };
void Address::setCountry(string x) { country = x; };
void Address::setCity(string x) { city = x; };




bool Address::equals(const Address& address) {
	if (this->house == address.house && this->city == address.city && this->country == address.country && this->street == address.street)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Address::print_address()
{
	cout << getHouse()<<', ' << getStreet() << ', ' << getCity() << ', ' << getCountry() << endl;
}

Address Address::copy_address()
{
	Address copy;
	copy.house = house;
	copy.street = street;
	copy.city = city;
	copy.country = country;
	return copy;
}

istream& operator>>(istream& in, Address& address) {
	std::cout << "Enter House: ";
	getline(in >> std::ws, address.house);
	cout << "Enter Street: ";
	getline(in >> std::ws, address.street);
	cout << "Enter City: ";
	getline(in >> std::ws, address.city);
	cout << "Enter Country: ";
	getline(in >> std::ws, address.country);
	return in;
}

bool Address::operator==(const Address& other) const {
	return house == other.house &&
		street == other.street &&
		city == other.city &&
		country == other.country;
}


string Address::toString() const
{
	return street + ", " + city + ", " + country;
}