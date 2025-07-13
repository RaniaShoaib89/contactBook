//#include "Address.h"
//#include "Contact.h"
//#include "ContactsBook.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//
//
//int main()
//{
//
//	cout << " 1. Create a contacts list from  given size(input size from user)" << endl;
//	cout << " 2. Add New Contact" << endl;
//	cout << " 3. Merge Duplicates" << endl;
//	cout << " 4. Store To File(input file name)" << endl;
//	cout << " 5. Load From File(input file name)" << endl;
//	cout << " 6. Print Contacts Sorted(input choice, fist_name or last_name)" << endl;
//	cout << " 7. Search contacts(all three choices)" << endl;
//	cout << " 8. Display Count of Contacts" << endl;
//	cout << " 9. Exit Program" << endl;
//	int n;
//	ContactsBook cbobj;
//	string first_name, last_name, address, phone;
//	char search_choice;
//	string sort;
//
//
//	
//	
//
//	int choice = 0;
//
//	do
//	{
//		cout << "Enter choice " << endl;
//		cin >> choice;
//		switch(choice)
//		{
//		case 1:
//			cout << "Enter size of contact list: " << endl;
//			cin >> n;
//			ContactsBook cbobj1(n);
//			cbobj = cbobj1;
//		   
//			break;
//		case 2:
//			
//
//		   Address aobj("house no 20", "A street", "Faisalabad", "Pakistan");
//			Contact cobj("Rania", "Shoaib", "0304567355", "raniashoaib6@gmail.com", &aobj);
//			cbobj.add_contact(cobj);
//			break;
//		case 3:
//			cbobj.merge_duplicates();
//			break;
//		case 4:
//			cbobj.save_to_file("SavedContacts");
//			break;
//		case 5:
//			cbobj.load_from_file("SavedContacts");
//			break;
//		case 6:
//			string sort;
//			cout << "Enter f/F for fist name sorting or l/L for last name sorting: " << endl;
//			cin >> sort;
//			cbobj.print_contacts_sorted(sort);
//			break;
//		case 7:
//			cout << "Enter A/a to search by address , N/n by name and P/p to search by phone number " << endl;
//			char search_choice;
//			switch (search_choice)
//			{
//			case 'A':
//			case 'a':
//				cout << "Enter address" << endl;
//				cin >> address;
//				cbobj.search_contact(address);
//				break;
//			case 'N':
//			case 'n':
//				cout << "Enter first name: " << endl;
//				cin >> first_name;
//				cout << "Enter last name : " << endl;
//				cin >> last_name;
//
//				cbobj.search_contact(first_name, last_name);
//				break;
//			case 'P':
//			case 'p':
//				cout << "Enter phonr number: " << endl;
//				cin >> phone;
//				cbobj.search_contact(phone);
//				break;
//			default:
//				cout << "No such searching mechanism " << endl;
//				break;
//
//			}
//			break;
//		case 8:
//			cout << "Total contacts : " << cbobj.total_contacts() << endl;
//			break;
//		case 9:
//			cout << "Exiting Program" << endl;
//			
//
//
//
//		
//
//			
//			
//
//
//
//		}
//		
//	}while (choice != 9);
//	system("pause");
//	return 0;
//}