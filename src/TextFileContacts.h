#ifndef TEXTFILECONTACTS_h
#define TEXTFILECONTACTS_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "TextFile.h"
#include "Contact.h"
#include "Utils.h"

using namespace std;

class TextFileContacts :public TextFile {
	const string TEXTFILE_TEMPORARY;
	int idContactLastInFile;
	
	Contact readContactFromLine(string lineWithContactData);
	int readIdUserFromLine(string lineWithContactData);
	int readIdContactFromLine(string lineWithContactData);
	
	string convertContactIntoStringsWithVerticalBars(Contact contact);
	void setNewIdContactLastInFile(int idContactDeleted);

public:
	TextFileContacts(string TEXTFILE) : TextFile(TEXTFILE), TEXTFILE_TEMPORARY("ContactsTemporary.txt") {
		idContactLastInFile = 0;
	};
	int getIdContactLastInFile();
	vector <Contact> readContactsOfLoggedInUserFromFile(int idUserLoggedIn);
	void addContactToFile(Contact contact);
	void deleteContactFromFile(int idContactDeleted);
	void editContactInFile(Contact contact);
};

#endif