#include <fstream>
#include "ContactsBook.h"
#include "HistoryObject.h"
#include "Contact.h"
#include "Group.h"
#include <algorithm>
#include "ResizableArray.h"
#include <string>



ifstream fin;
ofstream fout;
using namespace std;



void ContactsBook::add_contact(const Contact& contact)
{
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/

	
	if (full()) {
	
		resize_list();
	}

	
	contacts_list[contacts_count] = contact;
	contacts_count++;
	cout << "Contact added!" << endl;
}

int ContactsBook::total_contacts() const
{
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	//return -1;
	return contacts_count;
}

bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/
	//return false;
	if (contacts_count == size_of_contacts)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ContactsBook::resize_list()
{
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
	int new_size = size_of_contacts * 2;
	Contact* resized_list;
	resized_list = new Contact[new_size];
	for (int i = 0; i < contacts_count; i++)
	{
		resized_list[i] = *(contacts_list[i].copy_contact());
	}
	
	delete[] contacts_list;
	contacts_list = resized_list;
	size_of_contacts = new_size;
	
}

Contact* ContactsBook::search_contact( const string first_name, const string last_name)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
	//return nullptr;
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getFirstName() == first_name && contacts_list[i].getLastName() == last_name)
		{
			cout << "contact found " << endl;
			history.addSearchTerm(contacts_list[i].getFirstName());
			return contacts_list[i].copy_contact();
		}
		
		
	}
	cout << "No contact found " << endl;
	return nullptr;
    
}

Contact* ContactsBook::search_contact( string phone)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		if ( contacts_list[i].getMobileNumber() == phone)
		{
			history.addSearchTerm(contacts_list[i].getFirstName());
			return contacts_list[i].copy_contact();
			
		}
	}
	cout << "No contact found" << endl;
	return nullptr;
	
}

Contact* ContactsBook::search_contact(const Address& address)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getAddress()->equals(address))
		{
			history.addSearchTerm(contacts_list[i].getFirstName());
			return contacts_list[i].copy_contact();

		}
	}
	cout << "No contact found" << endl;
	return nullptr;


}
ContactsBook::ContactsBook() : contacts_count(0), contacts_list(nullptr), size_of_contacts(5) , history()
{
	contacts_list = new Contact[size_of_contacts]; 
	
}

ContactsBook::ContactsBook(int size_of_list) : history()
	
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
	
		size_of_contacts = size_of_list;
		contacts_list = new Contact[size_of_list];
		contacts_count = 0;
		
	   
		
		
	
}

Contact* ContactsBook::copy_contacts_list() const
{
	Contact* copy_list = new Contact[contacts_count];  
	for (int i = 0; i < contacts_count; i++) {
		copy_list[i] = contacts_list[i]; 
	}
	return copy_list;  
}

void ContactsBook::print_contacts_sorted( string choice)
{
	/*  
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* sorted_contacts = copy_contacts_list();
	sort_contacts_list(sorted_contacts, choice);
	
	
	
	for (int i = 0; i < contacts_count; i++) {
		cout << "Details of Contact [" << i + 1 << "] \n";
		cout << sorted_contacts[i].getFirstName() << ', ' << sorted_contacts[i].getLastName() << ', '
			<< sorted_contacts[i].getMobileNumber() << ', ' << sorted_contacts[i].getEmailAddress() << endl;
		sorted_contacts[i].getAddress()->print_address();

	}

	
	delete[] sorted_contacts;
}





void ContactsBook::sort_contacts_list(Contact* contacts_list,  string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
	
	if (contacts_count <= 0 || contacts_list == nullptr) {
		cout << "Contacts list is empty or invalid." <<  endl;
		return;
	}

	
	for (int i = 0; i < contacts_count - 1; ++i) {
		for (int j = i + 1; j < contacts_count; ++j) {
			
			bool swapNeeded = false;
			if (choice == "f" || choice == "F") {
				if (contacts_list[j].getFirstName() < contacts_list[i].getFirstName())
					swapNeeded = true;
			}
			else if (choice == "l" || choice == "L") {
				if (contacts_list[j].getLastName()[0] < contacts_list[i].getLastName()[0])
					swapNeeded = true;
			}
			else {
				cout << "Invalid choice for sorting." <<  endl;
				return;
			}

		
			if (swapNeeded) {
				
				Contact temp;
				temp = contacts_list[i];
				contacts_list[i] = contacts_list[j];
				contacts_list[j] = temp;
			}
		}
	}

	cout << "Contacts sorted successfully." <<  endl;
	

}

void ContactsBook::merge_duplicates()
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts
	
	for (int i = 0; i < contacts_count - 1; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			
			if (contacts_list[i].equals(contacts_list[j]))
			{   
				
				/*if (contacts_list[i].getMobileNumber() != contacts_list[j].getMobileNumber())
				{
					contacts_list[i].phone[num] = contacts_list[i].getMobileNumber();
					contacts_list[i].phone[num++] = contacts_list[j].getMobileNumber();
					if (contacts_list[i].phone[1] != "")
					{
						for (int num = 1; num < 5; num++)
						{
							contacts_list[i].phone[num] = contacts_list[i].getMobileNumber();
							contacts_list[i].phone[num] = contacts_list[j].getMobileNumber();
						}
					}
					
				}*/
				contacts_list[i].phone[0] = contacts_list[i].getMobileNumber();
				contacts_list[i].phone[1] = contacts_list[j].getMobileNumber();
				for (int k = j; k < contacts_count - 1; ++k)
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				contacts_count--; 
				j--;              
			}
		}
	}


}




void ContactsBook::load_from_file( string file_name)
{
	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close this file
	*/


	ifstream fin(file_name); 

	if (!fin.is_open())
	{
		cout << "Error opening file." << endl;
		return;
	}

	cout << "Loading contacts from file..." << endl;

	int loaded_contacts_count;
	
	fin >> loaded_contacts_count; 
	fin.ignore();                  

	cout << "contacts_count: " << loaded_contacts_count << endl; 
	

	for (int i = 0; i < loaded_contacts_count; ++i)
	{
		string first_name, last_name, phone, email_address;
		string house, street, city, country;

		
		if (getline(fin, first_name, ',') && getline(fin, last_name, ',') &&
			getline(fin, phone, ',') && getline(fin, email_address))
		{
			
			cout << "Contact details read from file of Contact "<<i+1<<" " << first_name << ", " << last_name << ", " << phone << ", " << email_address << endl;

			
			if (getline(fin, house, ',') && getline(fin, street, ',') &&
				getline(fin, city, ',') && getline(fin, country))
			{
				
				cout << "Address details read from file Contact "<<i + 1<<" "<< house << ", " << street << ", " << city << ", " << country << endl;
				Address* address = new Address(house, street, city, country);

				
				Contact contact(first_name, last_name, phone, email_address, address);

				
				add_contact(contact);
				contacts_count = loaded_contacts_count;
			
			}
			else
			{
				cout << "Error reading address details from file." << endl;
			}
		}
		else
		{
			cout << "Error reading contact details from file." << endl;
		}
		
	}
	

	fin.close(); 
}


void ContactsBook::save_to_file( string file_name)
{
	///*
	//*	In this function you will store all the contacts to a file
	//*	On first line store contacts_count
	//*	On next lines store contacts in the following format:
	//*       2 lines for each contact
	//*       On oneline write contact attributes(except address) in comma separated format. On second line
	//*	store address atributes in the same format
	//*	first_name,last_name,mobile_number,email_address
	//*	house,street,city,country
	//*	Close the file
	//*/
	
	fout.open(file_name.c_str(), ios::out);
	if (fout.is_open())
	{
		fout << contacts_count << endl;
		for (int i = 0; i < contacts_count; i++)
		{
			fout << contacts_list[i].getFirstName() << ',' << contacts_list[i].getLastName() << ',' << contacts_list[i].getMobileNumber()
				<< ',' << contacts_list[i].getEmailAddress() << endl;

			
			if (contacts_list[i].getAddress() != nullptr) {
				fout << contacts_list[i].getAddress()->getHouse() << ',' << contacts_list[i].getAddress()->getStreet() << ','
					<< contacts_list[i].getAddress()->getCity() << ',' << contacts_list[i].getAddress()->getCountry() << endl;
			}
			else {
				
				fout << "Address not available" << endl;
			}
		}
		
		fout.flush();
		fout.close();
		cout << "Contacts saved to file." << endl;
	}
	else
	{
		cout << "Error opening file for writing." << endl;
	}

}

istream& operator>>(istream& in, ContactsBook& contactsbook) {
	Contact cobj;
	in >> cobj;
	contactsbook.add_contact(cobj);

	return in;
}


ContactsBook::~ContactsBook()
{
	delete[] contacts_list;
	
}

ContactsBook& ContactsBook::operator=(const ContactsBook& obj) {

	if (this != &obj) {
		delete[] contacts_list;

		
		size_of_contacts = obj.size_of_contacts;
		contacts_count = obj.contacts_count;

		contacts_list = new Contact[size_of_contacts];
		for (int i = 0; i < min(contacts_count, size_of_contacts); i++) {
			contacts_list[i] = obj.contacts_list[i];
		}
	}
	return *this;
}

void ContactsBook::print_unsorted() const
{
	cout << "Printing contacts (Unsorted):" << endl;
	for (int i = 0; i < contacts_count; ++i)
	{
		cout << "Contact [" << i + 1 << "] :" << endl;
		cout << "First Name: " << contacts_list[i].getFirstName() << ", ";
		cout << "Last Name: " << contacts_list[i].getLastName() << ", ";
		/*cout << "Mobile Number: " << contacts_list[i].getMobileNumber() << ", ";
		cout << "Email Address: " << contacts_list[i].getEmailAddress() <<endl;
		Address* address = contacts_list[i].getAddress();
		if (address)
		{
			cout << "Address: " << ", ";
			cout << "House: " << address->getHouse() << ", ";
			cout << "Street: " << address->getStreet() << ", ";
			cout << "City: " << address->getCity() << ", ";
			cout << "Country: " << address->getCountry() << endl;
		}
		else
		{
			cout << "Address: N/A" << endl;
		}
		cout << endl;*/
	}
}

ContactsBook& ContactsBook::operator+=(const ContactsBook& obj)
{
	
	for (int i = 0; i < obj.contacts_count; ++i)
	{
		
		add_contact(obj.contacts_list[i]);
	}
	return *this; 
}


void ContactsBook::view_contact_details() const
{
	print_unsorted();
	int contact_index;
	cout << "Enter the index of the contact you want to view details of: ";
	cin >> contact_index;

	
	if (contact_index >= 1 && contact_index <= contacts_count) {
		
		Contact& selected_contact = contacts_list[contact_index - 1];
		cout << "Details of selected contact" << endl;
		cout << "First Name: " << selected_contact.getFirstName() << " ";
		cout << "Last Name: " << selected_contact.getLastName() << " ";
		//cout << "Mobile Number: " << selected_contact.getMobileNumber() << " ";
		
			cout << "Mobile number: " << selected_contact.phone[0] << "  ";
			cout << "Mobile number: " << selected_contact.phone[1] << "  ";
		
		cout << "Email Address: " << selected_contact.getEmailAddress() << endl;
		"Address: ";
		selected_contact.getAddress()->print_address();
	}
	else {
		cout << "Invalid index selected. Please select a valid index." << endl;
	}


}

void ContactsBook::update_contact()
{
	print_unsorted();
	int contact_index;
	cout << "Enter the index of the contact you want to updation of: ";
	cin >> contact_index;
	if (contact_index >= 1 && contact_index <= contacts_count) {

		Contact& selected_contact = contacts_list[contact_index - 1];
		cout << "Details of selected contact:" << endl;
		cout << "First Name: " << selected_contact.getFirstName() << endl;
		cout << "Last Name: " << selected_contact.getLastName() << endl;
		cout << "Mobile Number: " << selected_contact.getMobileNumber() << endl;
		cout << "Email Address: " << selected_contact.getEmailAddress() << endl;
		cout << "Address: ";
		selected_contact.getAddress()->print_address();
		cout << endl;

		string val; 
		cin.ignore();
		cout << "Enter first name [press enter to keep unchanged]" << endl;
		getline(cin, val);
		if (!val.empty())
			selected_contact.setFirstName(val);
		cout << "Enter last name [press enter to keep unchanged] " << endl;
		getline(cin, val);
		if (!val.empty())
			selected_contact.setLastName(val);
		cout << "Enter mobile number [press enter to keep unchanged] " << endl;
		getline(cin, val);
		if (!val.empty())
			selected_contact.setMobileNumber(val);
	    cout << "Enter email adddress [press enter to keep unchanged] " << endl;
		getline(cin, val);
		if (!val.empty())
			selected_contact.setEmailAddress(val);
		char set_address;
		cout << "Do you want to update address? type Y/y for yes and N/n for no " << endl;
		cin >> set_address;
		cin.ignore();
		if (set_address == 'y' || set_address == 'Y')
		{
			string house, street, city, country;
			cout << "Enter house: " << endl;
			getline(cin, house);
			cout << "Enter street: " << endl;
			getline(cin, street);
			cout << "Enter city: " << endl;
			getline(cin, city);
			cout << "Enter country: " << endl;
			getline(cin, country);
			selected_contact.setAddress(house, street, city, country);
		}
		else
		{
			cout << "Address not updated " <<endl;
		}
		


	}
	
	


	


}

void ContactsBook::delete_contact()
{
	print_unsorted();

	int contact_index;
	cout << "Enter the index of the contact you want to deletion of: ";
	cin >> contact_index;
	if (contact_index >= 1 && contact_index <= contacts_count) {


		char confirm_delete;
		cout << "Are you sure you want to delete this function? press Y/y for yes and any other key for no " << endl;
		cin >> confirm_delete;
		if (confirm_delete == 'Y' || confirm_delete == 'y')
		{
			for (int i = contact_index - 1; i < contacts_count - 1; i++)
			{
				contacts_list[i] = contacts_list[i + 1];
			}
			contacts_count--;

			cout << "Contact deleted " << endl;
			for (int i = 0; i < groups.getSize(); i++) {
				

				groups.getArray()[i]->removeContact(contacts_list[contact_index - 1]);
				
				}
			}
		else
		{
			cout << "Contact undeleted " << endl;
		}
		}
	}



void ContactsBook::search_advance(const string &str)
{
	for (int i = 0; i < contacts_count; ++i) 
	{
		const auto& contact = contacts_list[i];
		if (contact.matchesString(str))
		{
			cout << "Match found!" << endl;
			cout << "Name: " << contact.getFirstName() << " " << contact.getLastName()
				<< " Mobile number: " << contact.getMobileNumber() << " Email Address: " << contact.getEmailAddress() << endl;
			cout << "Address: ";
			//contact.getAddress()->print_address();
			cout << contact.getAddress()->getHouse() << " " << contact.getAddress()->getStreet() << " " << contact.getAddress()->getCity() << " " << contact.getAddress()->getCountry() << endl;


		}
		
	}
}




void ContactsBook::createGroup(const string& groupName) {
	cout << "Group created!" << endl;
	Group* newGroup = new Group(groupName);
	groups.addItem(newGroup);
}

void ContactsBook::deleteGroup(const string& groupName) {
	for (size_t i = 0; i < groups.getSize(); ++i) {
		Group* currentGroup = groups.getArray()[i];
		if (currentGroup->getGroupName() == groupName) {
			groups.removeItem(currentGroup);
			//delete currentGroup; 
			cout << "Group deleted." << endl;
			return;
		}
	}
	cout << "Group not found." << endl;
}
void ContactsBook::addContactToGroup(const  string& groupName, int contactIndex) {
	if (contactIndex >= 0 && contactIndex < contacts_count) {
	
		Group* group = nullptr;
		for (size_t i = 0; i < groups.getSize(); ++i) {
			if (groups.getArray()[i]->getGroupName() == groupName) {
				group = groups.getArray()[i];
				break;
			}
		}
		if (group != nullptr) {
			group->addContact(contacts_list[contactIndex]);
		}
		else {
			 cout << "Group '" << groupName << "' does not exist." <<  endl;
		}
	}
	else {
		 cout << "Invalid contact index." <<  endl;
	}
}

void ContactsBook::deleteContactFromGroup(const  string& groupName, int contactIndex) {
	if (contactIndex >= 0 && contactIndex < contacts_count) {
	
		Group* group = nullptr;
		for (size_t i = 0; i < groups.getSize(); ++i) {
			if (groups.getArray()[i]->getGroupName() == groupName) {
				group = groups.getArray()[i];
				break;
			}
		}
		if (group != nullptr) {
			group->removeContact(contacts_list[contactIndex]);
		}
		else {
			 cout << "Group '" << groupName << "' does not exist." <<  endl;
		}
	}
	else {
		 cout << "Invalid contact index." <<  endl;
	}
}

void ContactsBook::displayGroups() const {
	
	
	for (size_t i = 0; i < groups.getSize(); i++)
	{
		groups.getArray()[i]->printGroupContacts();
	}

}

//search_history
vector<string> ContactsBook::get_top_5_searches() const
{
	return history.getTop5Searches();
}