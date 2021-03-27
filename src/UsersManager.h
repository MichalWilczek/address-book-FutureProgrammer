#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "TextFileUsers.h"
#include "Utils.h"

using namespace std;

class UsersManager {
	int idUserLoggedIn;
	vector <User> users;
	TextFileUsers textFileUsers;
	
	User getUserNew();
	int getUserIdNew();
	bool doesLoginExist(string login);

public:
	UsersManager(string filenameUsers) : textFileUsers(filenameUsers) {
		users = textFileUsers.readUsersFromFile();
		idUserLoggedIn = 0;
	};
	bool isUserLoggedIn();
	int getIdUserLoggedIn();
	void showUsers();
	void registerUser();
	void logInUser();
	void changePasswordLoggedInUser();
	void logOutUser();
};

#endif
