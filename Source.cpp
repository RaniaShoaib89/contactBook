#include "Address.h"
#include "Contact.h"
#include "ContactsBook.h"
#include "Group.h"
#include "HistoryObject.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
   
   
    cout << " 1. Create a contacts list from given size(input size from user)" << endl;
    cout << " 2. Add New Contact" << endl;
    cout << " 3. Merge Duplicates" << endl;
    cout << " 4. Store To File(input file name)" << endl;
    cout << " 5. Load From File(input file name)" << endl;
    cout << " 6. Print Contacts Sorted(input choice, fist_name or last_name)" << endl;
    cout << " 7. Print Contacts unsorted(input choice, fist_name or last_name)" << endl;
    cout << " 8. Search contacts(all three choices)" << endl;
    cout << " 9. Display Count of Contacts" << endl;
    cout << "10. View contact details " << endl;
    cout << "11. Update contact details " << endl;
    cout << "12. Delete contact  " << endl;
    cout << "13. Advance Search" << endl;
    cout << "14. Add Group" << endl;
    cout << "15. Add Contact to Group" << endl;
    cout << "16. Detele Contact from Group" << endl;
    cout << "17. Delete Group" << endl;
    cout << "18. Display Groups" << endl;
    cout << "19. Save Search History to File" << endl;
    cout << "20. View Search History reverse sorted(latest first)" << endl;
    cout << "21. View frequently searched top 5 contacts;" << endl;
    cout << "22. Exit Program" << endl;

    int n;

    ContactsBook cbobj;
    Contact cobj;
    string first_name, last_name, email, phone, address;
    char search_choice;
    Address aobj;
    string highlighted_str;
    string group_name;
    int group_index;
    vector<string> top5;
    HistoryObject history("SearchedHIstory.txt");
 
   
    


   
   
 
   


    
    

    

    int choice = 0;

    do
    {  
        cout << "Enter choice: " << endl;
        cin >> choice;
        while (cin.fail() || choice<1 || choice>22 )
        {
            cin.clear();
            cin.ignore();
            cout << "ReEnter choice: " << endl;
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
        {
            cout << "Enter size of contact list: " << endl;
            cin >> n;

            ContactsBook cbobj1(n);
            for (int i = 0; i < n; i++)
            {
                cin >> cbobj1;
            }
            cbobj = cbobj1;
            
            


            break;
        }
        case 2:
        {   
            cout << "Enter contact details of new contact " << endl;
            cin >> cobj;
         
            
     
            cbobj.add_contact(cobj);
            break;
        }
        case 3:
           cbobj.merge_duplicates();
            break;
        case 4:
            cbobj.save_to_file("SavedContacts.txt");
            break;
        case 5:
            cbobj.load_from_file("SavedContacts.txt");
            break;
        case 6:
        {
            string sort;
            cout << "Enter f/F for first name sorting or l/L for last name sorting: " << endl;
            cin >> sort;
            cbobj.print_contacts_sorted(sort);
            break;
        }
        case 7:
            cbobj.print_unsorted();
            break;
        case 8:
            cout << "Enter A/a to search by address, N/n by name, and P/p to search by phone number: " << endl;
            cin >> search_choice;
            switch (search_choice)
            {
            case 'A':
            case 'a':
            {
                cout << "Enter address: " << endl;
                cin >> aobj;
               
                
                Contact* c = cbobj.search_contact(aobj);
                if (c != nullptr) {
                    cout << "Name:  " << c->getFirstName() << " " << c->getLastName() << "Mobile number : " << c->getMobileNumber() << "Email Address: " << c->getEmailAddress() << endl;
                    cout << "Address: " << endl;
                    c->getAddress()->print_address();
                }
                history.addSearchTerm(aobj.toString());
                break;
            }
            case 'N':
            case 'n':
            {
                cout << "Enter first name: " << endl;
                cin >> first_name;
                cout << "Enter last name: " << endl;
                cin >> last_name;
                Contact* c = cbobj.search_contact(first_name, last_name);
                if (c != nullptr)
                    cout << "Name " << c->getFirstName() << " " << c->getLastName() << c->getMobileNumber() << c->getEmailAddress();
                c->getAddress()->print_address();
                history.addSearchTerm(first_name + " " + last_name);


                break;
            }
            case 'P':
            case 'p':
            {
                cout << "Enter phone number: " << endl;
                cin >> phone;
                Contact* c = cbobj.search_contact(phone);
                if (c != nullptr)
                {

                    cout << "Name " << c->getFirstName() << " " << c->getLastName() << c->getMobileNumber() << c->getEmailAddress();
                    c->getAddress()->print_address();
                    history.addSearchTerm(phone);
                }
                
                break;
            }
            default:
                cout << "No such searching mechanism " << endl;
                break;
            }
            break;
        case 9:
            cout << "Total contacts: " << cbobj.total_contacts() << endl;
            break;
        case 10:
            cbobj.view_contact_details();
            break;
        case 11:
            cbobj.update_contact();
            break;
        case 12:
            cbobj.delete_contact();
            break;
        case 13:
        {
            cout << "Enter to search " << endl;
            cin >> highlighted_str;
            cbobj.search_advance(highlighted_str);
            break;
        }
        
        case 14:
            cout << "enter group name : " << endl; cin.ignore();
            getline(cin, group_name);
            cbobj.createGroup(group_name);
            break;
        case 15:
            cbobj.print_unsorted();
           
            cout << "Enter name of group " << endl; cin.ignore();
            getline(cin, group_name);
            cout << "Select index: " << endl;
            cin >> group_index;
            cbobj.addContactToGroup(group_name, group_index - 1);
            break;
        case 16:
            cbobj.print_unsorted();
            cout << "Enter name of group " << endl; cin.ignore();
            getline(cin, group_name);
            cout << "Select index: " << endl;
            cin >> group_index;
            cbobj.deleteContactFromGroup(group_name, group_index - 1);
            break;
        case 17:
            cout << "enter group name : " << endl; cin.ignore();
            getline(cin, group_name);
            cbobj.deleteGroup(group_name);
            break;
        case 18:
         
            cbobj.displayGroups();
            break;
        case 19: 
            history.~history();
            
            cout << "Search history saved to file." << endl;
            break;
        
        case 20:
            cout << "Viewing Search History:" << endl;
            history.printSearchHistory();
            break;
        case 21:
        {
            top5 = history.getTop5Searches();
            cout << "Top 5 searched terms:" << endl;
            for (const string& term : top5)
            {
                cout << term << endl;
            }
            break;
        }
        

        case 22:
            cout << "Exiting Program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (choice != 22);






    
    return 0;
}

