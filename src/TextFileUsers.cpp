#include "TextFileUsers.h"


void TextFileUsers::addUserToFile(User user) {

    string lineWithUserData = "";
    fstream textFile;
    textFile.open(FILENAME.c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithUserData = convertUserIntoStringsWithVerticalBars(user);

        if (isFileEmpty(textFile) == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData;
        }
    } else
        cout << "The file: " << FILENAME << " cannot be opened. No data are saved to file." << endl;
    textFile.close();
}

string TextFileUsers::convertUserIntoStringsWithVerticalBars(User user) {
    string lineWithUserData = "";

    lineWithUserData += Utils::convertIntIntoString(user.getIdContact()) + '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

vector <User> TextFileUsers::readUsersFromFile() {
    
    vector <User> users;
    
    User user;
    string lineWitUserData = "";

    fstream textFile;
    textFile.open(FILENAME.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, lineWitUserData)) {
            user = getUser(lineWitUserData);
            users.push_back(user);
        }
    }
    textFile.close();
    return users;
}

User TextFileUsers::getUser(string lineWitUserData) {
    User user;
    string userDataElement = "";
    int numberUserDataElement = 1;

    for (int signPosition = 0; signPosition < lineWitUserData.length(); signPosition++) {
        if (lineWitUserData[signPosition] != '|') {
            userDataElement += lineWitUserData[signPosition];
        } else {
            switch (numberUserDataElement) {
            case 1:
                user.setIdContact(atoi(userDataElement.c_str()));
                break;
            case 2:
                user.setLogin(userDataElement);
                break;
            case 3:
                user.setPassword(userDataElement);
                break;
            }
            userDataElement = "";
            numberUserDataElement++;
        }
    }
    return user;
}

void TextFileUsers::saveUsersToFile(vector <User> users) {
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(FILENAME.c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserData = convertUserIntoStringsWithVerticalBars(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "The file: " << FILENAME << " cannot be opened." << endl;
    }
    textFile.close();
}
