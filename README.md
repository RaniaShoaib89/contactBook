# Contact Management System

A comprehensive C++ console application for managing personal and professional contacts with advanced features like grouping, search history, and file persistence.

## 🚀 Features

### Core Contact Management
- **Add New Contacts**: Store complete contact information including name, phone, email, and address
- **Update Contact Details**: Modify existing contact information
- **Delete Contacts**: Remove unwanted contacts from the system
- **Merge Duplicates**: Automatically identify and merge duplicate contact entries
- **View Contact Details**: Display comprehensive contact information

### Advanced Search & Organization
- **Multi-Search Options**: Search contacts by:
  - Name (first name + last name)
  - Phone number
  - Address
- **Search History**: Track and display top 5 most searched queries
- **Sorted Display**: View contacts sorted by first name or last name

### Group Management
- **Create Groups**: Organize contacts into custom groups
- **Add/Remove from Groups**: Manage group memberships
- **Display Groups**: View all groups and their members
- **Delete Groups**: Remove entire groups when no longer needed

### File Operations
- **Save to File**: Persist contact data to external files
- **Load from File**: Import contacts from saved files
- **Automatic Backup**: Maintain contact data between sessions

### Additional Features
- **Dynamic Array Management**: Automatically resize contact list as needed
- **Contact Count**: Display total number of stored contacts
- **History Tracking**: Keep track of user interactions and searches

## 🏗️ Project Architecture

### Core Classes

#### `Contact`
- Stores individual contact information (name, phone, email, address)
- Handles contact comparison and copying operations
- Supports input/output operations

#### `ContactsBook` 
- Main container for managing multiple contacts
- Implements search, sort, and file operations
- Manages groups and maintains search history
- Supports dynamic resizing and duplicate management

#### `Address`
- Handles complete address information (house, street, city, country)
- Provides address comparison and manipulation methods

#### `Group`
- Manages contact grouping functionality
- Allows categorization of contacts for better organization

#### `ResizableArray`
- Template class for dynamic array management
- Automatically handles memory allocation and resizing

#### `HistoryObject`
- Tracks user search patterns and frequently accessed contacts
- Maintains search history for improved user experience

## 🛠️ Technical Implementation

- **Language**: C++
- **Development Environment**: Microsoft Visual Studio
- **Memory Management**: Dynamic allocation with proper cleanup
- **File I/O**: Text-based file storage and retrieval
- **Data Structures**: Dynamic arrays, vectors, and custom classes
- **Design Patterns**: Object-oriented design with proper encapsulation

## 📦 Installation & Setup

### Prerequisites
- Microsoft Visual Studio (2019 or later recommended)
- Windows operating system
- C++ compiler with C++11 support or later

### Building the Project
1. Clone this repository
2. Open `mini_project.vcxproj` in Visual Studio
3. Build the solution (Ctrl+Shift+B)
4. Run the executable from the Debug/Release folder

## 🎮 Usage

### Main Menu Options
1. **Create Contact List**: Initialize a new contact list with specified size
2. **Add New Contact**: Add a contact with complete information
3. **Merge Duplicates**: Find and merge duplicate entries
4. **Store To File**: Save current contacts to a file
5. **Load From File**: Load contacts from a saved file
6. **Print Contacts Sorted**: Display contacts sorted by name
7. **Search Contacts**: Find contacts using various search criteria
8. **Display Count**: Show total number of contacts
9. **Exit Program**: Close the application

### Search Operations
- **By Name**: Enter first and last name
- **By Phone**: Enter phone number
- **By Address**: Enter address details

### File Operations
- Contacts are saved in plain text format
- Default files: `SavedContacts.txt`, `SearchedHistory.txt`
- Custom file names supported for save/load operations

## 📁 File Structure
```
├── Contact.h/cpp          # Contact class implementation
├── ContactsBook.h/cpp     # Main contact book management
├── Address.h/cpp          # Address handling
├── Group.h/cpp            # Group management
├── HistoryObject.h/cpp    # Search history tracking
├── ResizableArray.h/cpp   # Dynamic array implementation
├── Source.cpp             # Main application entry point
├── main.cpp               # Alternative main implementation
└── mini_project.vcxproj   # Visual Studio project file
```

## 🔮 Future Enhancements
- GUI implementation using Qt or Windows Forms
- Database integration (SQLite/MySQL)
- Contact import/export (CSV, vCard formats)
- Advanced search filters and sorting options
- Contact photo support
- Backup and restore functionality

## 👨‍💻 Developer
**Rania Shoaib**  
*Software Engineering Student*

## 📝 License
This project is created for educational purposes as part of a programming course.

---
*Built with ❤️ using C++ and Visual Studio*
