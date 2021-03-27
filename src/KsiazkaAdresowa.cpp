#include "ContactBook.h"


void ContactBook::registerUser() {
	usersManager.registerUser();
}

void ContactBook::showUsers() {
	usersManager.showUsers();
}

void ContactBook::logInUser() {
	usersManager.logInUser();
	if (usersManager.czyUzytkownikJestZalogowany()) {
		addressesManager = new ContactsManager(NAZWA_PLIKU_Z_ADRESATAMI, usersManager.pobierzIdZalogowanegoUzytkownika());
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
	if (usersManager.czyUzytkownikJestZalogowany()) {
		addressesManager->addContact(usersManager.pobierzIdZalogowanegoUzytkownika());
	} else {
		cout << "Log in first to add contact." << endl;
		system("pause");
	}
}

void ContactBook::showContactsOfLoggedInUser() {
	if (usersManager.czyUzytkownikJestZalogowany()) {
		addressesManager->showContactsOfLoggedInUser();
	}
	else {
		cout << "Log in first to show contacts." << endl;
		system("pause");
	}
}

void ContactBook::searchContactByFirstName() {
    if (usersManager.czyUzytkownikJestZalogowany()) {
        addressesManager->searchContactByFirstName();
    }
    else {
        cout << "Log in first to find contacts by first name." << endl;
        system("pause");
    }
}

void ContactBook::searchContactBySurname() {
    if (usersManager.czyUzytkownikJestZalogowany()) {
        addressesManager->searchContactBySurname();
    }
    else {
        cout << "Log in first to find contacts by surname." << endl;
        system("pause");
    }
}

void ContactBook::deleteContact() {
    if (usersManager.czyUzytkownikJestZalogowany()) {
        addressesManager->deleteContact();
    }
    else {
        cout << "Log in first to delete contact." << endl;
        system("pause");
    }
}

void ContactBook::editContact() {
    if (usersManager.czyUzytkownikJestZalogowany()) {
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
        if (!usersManager.czyUzytkownikJestZalogowany()) {
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
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char ContactBook::chooseOptionUserMenu() {
    char wybor = { 0 };

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
