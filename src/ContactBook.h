#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <iostream>
#include <string>
#include "UsersManager.h"
#include "ContactsManager.h"
#include "Utils.h"
using namespace std;

class ContactBook {
	UsersManager usersManager;
	ContactsManager *addressesManager;
	const string TEXTFILE_CONTACTS;
	
	char chooseOptionMainMenu();
	char chooseOptionUserMenu();

public:
	ContactBook(string textfileUsers, string textfileContacts) :
		usersManager(textfileUsers), TEXTFILE_CONTACTS(textfileContacts) {
		addressesManager = NULL;
	};
	~ContactBook() {
		delete addressesManager;
		addressesManager = NULL;
	}

	void registerUser();
	void showUsers();
	void logInUser();
	void changePasswordLoggedInUser();
	void logOutUser();
	void addContact();
	void searchContactByFirstName();
	void searchContactBySurname();
	void showContactsOfLoggedInUser();
	void deleteContact();
	void editContact();
	void run();
};

#endif
