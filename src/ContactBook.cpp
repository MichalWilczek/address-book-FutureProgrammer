#include "ContactBook.h"


void ContactBook::registerUser() {
	usersManager.registerUser();
}

void ContactBook::showUsers() {
	usersManager.showUsers();
}

void ContactBook::logInUser() {
	usersManager.logInUser();
	if (usersManager.isUserLoggedIn()) {
		addressesManager = new ContactsManager(NAZWA_PLIKU_Z_ADRESATAMI, usersManager.getIdUserLoggedIn());
	}
}

void ContactBook::changePasswordLoggedInUser() {
	usersManager.changePasswordLoggedInUser();
}

void ContactBook::logOutUser() {
	usersManager.logOutUser();
	delete addressesManager;
	addressesManager = NULL;
}

void ContactBook::addContact() {
	if (usersManager.isUserLoggedIn()) {
		addressesManager->addContact(usersManager.getIdUserLoggedIn());
	} else {
		cout << "Log in first to add contact." << endl;
		system("pause");
	}
}

void ContactBook::showContactsOfLoggedInUser() {
	if (usersManager.isUserLoggedIn()) {
		addressesManager->showContactsOfLoggedInUser();
	}
	else {
		cout << "Log in first to show contacts." << endl;
		system("pause");
	}
}

void ContactBook::searchContactByFirstName() {
    if (usersManager.isUserLoggedIn()) {
        addressesManager->searchContactByFirstName();
    }
    else {
        cout << "Log in first to find contacts by first name." << endl;
        system("pause");
    }
}

void ContactBook::searchContactBySurname() {
    if (usersManager.isUserLoggedIn()) {
        addressesManager->searchContactBySurname();
    }
    else {
        cout << "Log in first to find contacts by surname." << endl;
        system("pause");
    }
}

void ContactBook::deleteContact() {
    if (usersManager.isUserLoggedIn()) {
        addressesManager->deleteContact();
    }
    else {
        cout << "Log in first to delete contact." << endl;
        system("pause");
    }
}

void ContactBook::editContact() {
    if (usersManager.isUserLoggedIn()) {
        addressesManager->editContact();
    }
    else {
        cout << "Log in first to edit contact." << endl;
        system("pause");
    }
}

void ContactBook::run() {
    char wybor = { 0 };

    while (true) {
        if (!usersManager.isUserLoggedIn()) {
            wybor = chooseOptionMainMenu();

            switch (wybor) {
            case '1':
                registerUser();
                break;
            case '2':
                logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No such option available." << endl << endl;
                system("pause");
                break;
            }
        } else {
            wybor = chooseOptionUserMenu();

            switch (wybor) {
            case '1':
                addContact();
                break;
            case '2':
                searchContactByFirstName();
                break;
            case '3':
                searchContactBySurname();
                break;
            case '4':
                showContactsOfLoggedInUser();
                break;
            case '5':
                deleteContact();
                break;
            case '6':
                editContact();
                break;
            case '7':
                changePasswordLoggedInUser();
                break;
            case '8':
                logOutUser();
                break;
            }
        }
    }
}

char ContactBook::chooseOptionMainMenu() {
    char wybor = { 0 };

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    wybor = Utils::readSign();

    return wybor;
}

char ContactBook::chooseOptionUserMenu() {
    char wybor = { 0 };

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add contact" << endl;
    cout << "2. Search contact by first name" << endl;
    cout << "3. Search contact by surname" << endl;
    cout << "4. Show contacts" << endl;
    cout << "5. Delete contact" << endl;
    cout << "6. Edit contact" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    wybor = Utils::readSign();

    return wybor;
}
