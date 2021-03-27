#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <string>
#include "UsersManager.h"
#include "ContactsManager.h"
#include "Utils.h"
using namespace std;

class ContactBook {
	UsersManager usersManager;
	ContactsManager *addressesManager;
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	
	char chooseOptionMainMenu();
	char chooseOptionUserMenu();

public:
	ContactBook(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
		usersManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
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
