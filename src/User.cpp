#include "User.h"


void User::setIdContact(int newId) {
	if (newId >= 0)
		idUser = newId;
}

void User::setLogin(string newLogin) {
	login = newLogin;
}

void User::setPassword(string newPassword) {
	password = newPassword;
}

int User::getIdContact() {
	return idUser;
}

string User::getLogin() {
	return login;
}

string User::getPassword() {
	return password;
}