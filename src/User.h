#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
	int idUser;
	string login;
	string password;

public:
	User(int idUser=0, string login="", string password="") {
		this->idUser = idUser;
		this->login = login;
		this->password = password;
	}

	void setIdContact(int newId);
	void setLogin(string newLogin);
	void setPassword(string newPassword);

	int getIdContact();
	string getLogin();
	string getPassword();
};

#endif
