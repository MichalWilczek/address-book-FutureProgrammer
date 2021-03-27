#ifndef CONTACTSMANAGER_h
#define CONTACTSMANAGER_h

#include <iostream>
#include <vector>

#include "Contact.h"
#include "TextFileContacts.h"

using namespace std;

class ContactsManager {
	const int ID_USER_LOGGED_IN;	
	vector <Contact> contacts;
	TextFileContacts textFileContacts;

	void showContact(Contact contact);
	Contact setNewContact(int idUserLoggedIn);
	int getIdContactFromClient();
	static void showAmountOfFoundContacts(int amountContacts);
	char chooseOptionEditionMenu();

public:
	ContactsManager(string filenameContacts, int idUserLoggedIn)
		: textFileContacts(filenameContacts), ID_USER_LOGGED_IN(idUserLoggedIn) {
		contacts = textFileContacts.readContactsOfLoggedInUserFromFile(ID_USER_LOGGED_IN);
	};
	void addContact(int idUserLoggedIn);
	void deleteContact();
	void editContact();
	void showContactsOfLoggedInUser();
	void searchContactByFirstName();
	void searchContactBySurname();
};

#endif