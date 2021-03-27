#include "Contact.h"


void Contact::setIdContact(int newIdContact) {
	if (newIdContact >= 0)
		idUser = newIdContact;
}

void Contact::setIdUser(int newIdUser) {
	if (newIdUser >= 0)
		idContact = newIdUser;
}

void Contact::setFirstName(string newFirstName) {
	firstName = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(newFirstName);
}

void Contact::setSurname(string newSurname) {
	surname = Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(newSurname);
}

void Contact::setPhoneNumber(string newPhoneNumber) {
	phoneNumber = newPhoneNumber;
}

void Contact::setEmail(string newEmail) {
	email = newEmail;
}

void Contact::setAddress(string newAddress) {
	address = newAddress;
}


int Contact::getIdContact() {
	return idUser;
}

int Contact::getIdUser() {
	return idContact;
}

string Contact::getFirstName() {
	return firstName;
}

string Contact::getSurname() {
	return surname;
}

string Contact::getPhoneNumber() {
	return phoneNumber;
}

string Contact::getEmail() {
	return email;
}

string Contact::getAddress() {
	return address;
}
