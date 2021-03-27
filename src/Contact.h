#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include "Utils.h"

using namespace std;

class Contact {
	int idUser;
	int idContact;
	string firstName;
	string surname;
	string phoneNumber;
	string email;
	string address;

public:
	Contact(int idUser=0, int idContact=0, string firstName="", string surname="", string phoneNumber="", string email="", string address="") {
		this->idUser = idUser;
		this->idContact = idContact;
		this->firstName = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(firstName);
		this->surname = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(surname);
		this->phoneNumber = phoneNumber;
		this->email = email;
		this->address = address;
	}

	void setIdContact(int newIdContact);
	void setIdUser(int newIdUser);
	void setFirstName(string newFirstName);
	void setSurname(string newSurname);
	void setPhoneNumber(string newPhoneNumber);
	void setEmail(string newEmail);
	void setAddress(string newAddress);

	int getIdContact();
	int getIdUser();
	string getFirstName();
	string getSurname();
	string getPhoneNumber();
	string getEmail();
	string getAddress();
};

#endif
