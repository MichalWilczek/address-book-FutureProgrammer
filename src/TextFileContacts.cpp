#include "TextFileContacts.h"
#include <windows.h>


int TextFileContacts::getIdContactLastInFile() {
    return idContactLastInFile;
}

vector <Contact> TextFileContacts::readContactsOfLoggedInUserFromFile(int idUserLoggedIn) {
    vector <Contact> contacts;
    Contact contact;
    string lineWithContactData = "";
    string contactDataLastInFile = "";
    fstream textFile;
    textFile.open(FILENAME.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, lineWithContactData)) {
            if (idUserLoggedIn == readIdUserFromLine(lineWithContactData)) {
                contact = readContactFromLine(lineWithContactData);
                contacts.push_back(contact);
            }
        }
        contactDataLastInFile = lineWithContactData;
    }
    else
        cout << "The file: " << FILENAME << " cannot be opened. Data are not uploaded." << endl;

    textFile.close();

    if (contactDataLastInFile != "") {
        idContactLastInFile = readIdContactFromLine(contactDataLastInFile);
    }

    return contacts;
}

void TextFileContacts::deleteContactFromFile(int idContactDeleted) {
    fstream textFileUploaded, textFileTemporary;
    string lineWithContactData = "";
    bool firstLineSaved = true;

    textFileUploaded.open(FILENAME, ios::in);
    textFileTemporary.open(TEXTFILE_TEMPORARY, ios::out | ios::app);

    if (textFileUploaded.good() == true)
    {
        while (getline(textFileUploaded, lineWithContactData))
        {
            int idWczytanegoAdresata = readIdContactFromLine(lineWithContactData);
            
            // Exclude the line with deleted contact.
            if (idWczytanegoAdresata != idContactDeleted) {
                if (firstLineSaved) {
                    textFileTemporary << lineWithContactData;
                    firstLineSaved = false;
                } else {
                    textFileTemporary << endl << lineWithContactData;
                }
            }
        }
        textFileUploaded.close();
        textFileTemporary.close();

        deleteFile(FILENAME);
        changeFilename(TEXTFILE_TEMPORARY, FILENAME);

        setNewIdContactLastInFile(idContactDeleted);
    }
}

void TextFileContacts::setNewIdContactLastInFile(int idContactDeleted) {
    if (idContactDeleted == idContactLastInFile) {
        idContactLastInFile = 0;
        string lineWithContactData = "";
        string ContactDataLastInFile = "";
        fstream textFile;
        textFile.open(FILENAME, ios::in);

        if (textFile.good() == true)
        {
            while (getline(textFile, lineWithContactData)) {}
            ContactDataLastInFile = lineWithContactData;
            textFile.close();
        }
        else
            cout << "The file: " << FILENAME << " cannot be opened. Data are not uploaded." << endl;

        if (ContactDataLastInFile != "")
        {
            idContactLastInFile = readIdContactFromLine(ContactDataLastInFile);
        }
    }
}

void TextFileContacts::editContactInFile(Contact contact) {
    fstream textFileUploaded, textFileTemporary;
    string lineWithContactDataForEditing = convertContactIntoStringsWithVerticalBars(contact);
    string lineWithContactData = "";
    int numberUploadedLine = 1;

    textFileUploaded.open(FILENAME, ios::in);
    textFileTemporary.open(TEXTFILE_TEMPORARY, ios::out | ios::app);

    if (textFileUploaded.good() == true)
    {
        while (getline(textFileUploaded, lineWithContactData))
        {
            int idAdresata = readIdContactFromLine(lineWithContactData);

            // Save edited contact.
            if (idAdresata == contact.getIdContact()) {
                if (numberUploadedLine == 1)
                    textFileTemporary << lineWithContactDataForEditing;
                else if (numberUploadedLine > 1)
                    textFileTemporary << endl << lineWithContactDataForEditing;
            
            // Save non-edited contacts.
            } else {
                if (numberUploadedLine == 1)
                    textFileTemporary << lineWithContactData;
                else if (numberUploadedLine > 1)
                    textFileTemporary << endl << lineWithContactData;
            }

            numberUploadedLine++;
        }
        textFileUploaded.close();
        textFileTemporary.close();

        deleteFile(FILENAME);
        changeFilename(TEXTFILE_TEMPORARY, FILENAME);
    }
    cout << endl << "Contact data are updated." << endl << endl;
}

Contact TextFileContacts::readContactFromLine(string lineWithContactData) {
    Contact contact;
    string contactDataElement = "";
    int numberContactDataElement = 1;

    for (int signPosition = 0; signPosition < lineWithContactData.length(); signPosition++) {
        if (lineWithContactData[signPosition] != '|') {
            contactDataElement += lineWithContactData[signPosition];
        }
        else {
            switch (numberContactDataElement) {
            case 1:
                contact.setIdContact(atoi(contactDataElement.c_str()));
                break;
            case 2:
                contact.setIdUser(atoi(contactDataElement.c_str()));
                break;
            case 3:
                contact.setFirstName(contactDataElement);
                break;
            case 4:
                contact.setSurname(contactDataElement);
                break;
            case 5:
                contact.setPhoneNumber(contactDataElement);
                break;
            case 6:
                contact.setEmail(contactDataElement);
                break;
            case 7:
                contact.setAddress(contactDataElement);
                break;
            }
            contactDataElement = "";
            numberContactDataElement++;
        }
    }
    return contact;
}

int TextFileContacts::readIdUserFromLine(string lineWithContactData) {
    int idUserStartPosition = lineWithContactData.find_first_of('|') + 1;
    int idContact = Utils::convertStringIntoInt(
        Utils::readNumber(lineWithContactData, idUserStartPosition));

    return idContact;
}

int TextFileContacts::readIdContactFromLine(string lineWithContactData) {
    int idContactStartPosition = 0;

    string idContactStr = Utils::readNumber(lineWithContactData, idContactStartPosition);
    int idContact = Utils::convertStringIntoInt(idContactStr);
    return idContact;
}

void TextFileContacts::addContactToFile(Contact contact) {
    string lineWithContactData = "";
    fstream textFile;
    textFile.open(FILENAME.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        lineWithContactData = convertContactIntoStringsWithVerticalBars(contact);

        if (isFileEmpty(textFile) == true) {
            textFile << lineWithContactData;
        } else {
            textFile << endl << lineWithContactData;
        }
    } else {
        cout << "The file: " << FILENAME << " cannot be opened. Data are not uploaded." << endl;
    }
    idContactLastInFile++;
    textFile.close();
    system("pause");
}

string TextFileContacts::convertContactIntoStringsWithVerticalBars(Contact contact) {
    string lineWithContactData = "";

    lineWithContactData += Utils::convertIntIntoString(contact.getIdContact()) + '|';
    lineWithContactData += Utils::convertIntIntoString(contact.getIdUser()) + '|';
    lineWithContactData += contact.getFirstName() + '|';
    lineWithContactData += contact.getSurname() + '|';
    lineWithContactData += contact.getPhoneNumber() + '|';
    lineWithContactData += contact.getEmail() + '|';
    lineWithContactData += contact.getAddress() + '|';

    return lineWithContactData;
}
