#ifndef TEXTFILEUSERS_h
#define TEXTFILEUSERS_h

#include <iostream>
#include <vector>
#include <fstream>

#include "TextFile.h"
#include "User.h"
#include "Utils.h"

using namespace std;

class TextFileUsers :public TextFile {
	string convertUserIntoStringsWithVerticalBars(User user);
	User getUser(string lineWithUserData);

public:
	TextFileUsers(string FILENAME) : TextFile(FILENAME) {};
	void addUserToFile(User user);
	vector <User> readUsersFromFile();
	void saveUsersToFile(vector <User> users);
};

#endif
