#include "ContactsManager.h"


void ContactsManager::addContact(int idUserLoggedIn) {
    Contact contact;

    system("cls");
    cout << " >>> ADDING CONTACT <<<" << endl << endl;
    contact = setNewContact(idUserLoggedIn);

    contacts.push_back(contact);
    textFileContacts.addContactToFile(contact);
}

void ContactsManager::deleteContact() {
    int idContactDeleted = 0;
    int lineNumberOfDeletedContact = 0;

    system("cls");
    cout << ">>> DELETING CONTACT <<<" << endl << endl;
    idContactDeleted = getIdContactFromClient();

    char sign;
    bool doesContactExist = false;

    for (vector <Contact>::iterator itr = contacts.begin(); itr != contacts.end(); itr++) {
        if (itr->getIdContact() == idContactDeleted) {
            doesContactExist = true;
            cout << endl << "Confirm by clicking 't': ";
            sign = Utils::readSign();
            if (sign == 't') {
                textFileContacts.deleteContactFromFile(idContactDeleted);
                contacts.erase(itr);
                cout << endl << endl << "Contact DELETED." << endl << endl;              
            } else {
                cout << endl << endl << "Contact is NOT deleted." << endl << endl;
            }
            system("pause");
            return;
        }
    }
    if (doesContactExist == false) {
        cout << endl << "No such contact in the contact book." << endl << endl;
        system("pause");
    }
}

void ContactsManager::editContact() {
    system("cls");
    Contact contact;
    int idContactEdited = 0;
    int lineNumberWithEditedContact = 0;
    string lineWithContactData = "";

    cout << ">>> EDITING CONTACT <<<" << endl << endl;
    idContactEdited = getIdContactFromClient();

    char choice;
    bool doesContactExist = false;

    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].getIdContact() == idContactEdited) {
            doesContactExist = true;
            choice = chooseOptionEditionMenu();

            switch (choice) {
            case '1':
                cout << "Set new first name: ";
                contacts[i].setFirstName(Utils::readLine());
                textFileContacts.editContactInFile(contacts[i]);
                break;
            case '2':
                cout << "Set new surname: ";
                contacts[i].setSurname(Utils::readLine());
                textFileContacts.editContactInFile(contacts[i]);
                break;
            case '3':
                cout << "Set new phone number: ";
                contacts[i].setPhoneNumber(Utils::readLine());
                textFileContacts.editContactInFile(contacts[i]);
                break;
            case '4':
                cout << "Set new email: ";
                contacts[i].setEmail(Utils::readLine());
                textFileContacts.editContactInFile(contacts[i]);
                break;
            case '5':
                cout << "Set new address: ";
                contacts[i].setAddress(Utils::readLine());
                textFileContacts.editContactInFile(contacts[i]);
                break;
            case '6':
                cout << endl << "Exit to user menu." << endl << endl;
                break;
            default:
                cout << endl << "No such option available! Exit to user menu." << endl << endl;
                break;
            }
        }
    }
    if (doesContactExist == false) {
        cout << endl << "No such contact available." << endl << endl;
    }
    system("pause");
}

int ContactsManager::getIdContactFromClient()
{
    int idContact = 0;
    cout << "Give contact ID: ";
    idContact = Utils::readInteger();
    return idContact;
}

Contact ContactsManager::setNewContact(int idUserLoggedIn) {
    
    cout << "Give first name: ";
    string firstName = Utils::readLine();

    cout << "Give surname: ";
    string surname = Utils::readLine();

    cout << "Give phone number: ";
    string phoneNumber = Utils::readLine();

    cout << "Give email: ";
    string email = Utils::readLine();

    cout << "Give address: ";
    string address = Utils::readLine();

    int idContactNew = textFileContacts.getIdContactLastInFile() + 1;
    Contact adresat(idContactNew, idUserLoggedIn, firstName, surname, phoneNumber, email, address);
    return adresat;
}

void ContactsManager::showContactsOfLoggedInUser() {
    system("cls");
    if (!contacts.empty()) {
        cout << "             >>> CONTACTS <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Contact> ::iterator itr = contacts.begin(); itr != contacts.end(); itr++) {
            showContact(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Contact book is empty." << endl << endl;
    }
    system("pause");
}

void ContactsManager::searchContactByFirstName() {
    string contactFirstNameSearched = "";
    int contactsAmount = 0;

    system("cls");
    if (!contacts.empty())
    {
        cout << ">>> SEARCHING CONTACTS BY FIRST NAME <<<" << endl << endl;

        cout << "Search contacts by first name: ";
        contactFirstNameSearched = Utils::readLine();
        contactFirstNameSearched = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(contactFirstNameSearched);

        for (vector <Contact>::iterator itr = contacts.begin(); itr != contacts.end(); itr++)
        {
            if (itr->getFirstName() == contactFirstNameSearched)
            {
                showContact(*itr);
                contactsAmount++;
            }
        }
        showAmountOfFoundContacts(contactsAmount);
    }
    else
    {
        cout << endl << "Contact book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void ContactsManager::searchContactBySurname() {
    string contactSurnameSearched;
    int contactsAmount = 0;

    system("cls");
    if (!contacts.empty())
    {
        cout << ">>> SEARCHING CONTACTS BY SURNAME <<<" << endl << endl;

        cout << "Search contacts by surname: ";
        contactSurnameSearched = Utils::readLine();
        contactSurnameSearched = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(contactSurnameSearched);

        for (vector <Contact>::iterator itr = contacts.begin(); itr != contacts.end(); itr++)
        {
            if (itr->getSurname() == contactSurnameSearched)
            {
                showContact(*itr);
                contactsAmount++;
            }
        }
        showAmountOfFoundContacts(contactsAmount);
    }
    else
    {
        cout << endl << "Contact book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void ContactsManager::showAmountOfFoundContacts(int contactsAmount) {
    if (contactsAmount == 0)
        cout << endl << "No contacts available with these data in the contact book." << endl;
    else
        cout << endl << "Amount of contacts in the contact book is: " << contactsAmount << endl << endl;
}

void ContactsManager::showContact(Contact contact) {
    cout << endl << "Id:                " << contact.getIdContact() << endl;
    cout << "First name:        " << contact.getFirstName() << endl;
    cout << "Surname:           " << contact.getSurname() << endl;
    cout << "Phone number:      " << contact.getPhoneNumber() << endl;
    cout << "Email:             " << contact.getEmail() << endl;
    cout << "Address:           " << contact.getAddress() << endl;
}

char ContactsManager::chooseOptionEditionMenu() {
    char wybor;

    cout << endl << "   >>> MENU EDITION  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Which data should be updated: " << endl;
    cout << "1 - First name" << endl;
    cout << "2 - Surname" << endl;
    cout << "3 - Phone number" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Address" << endl;
    cout << "6 - Exit " << endl;
    cout << endl << "Your choice: ";
    wybor = Utils::readSign();

    return wybor;
}
