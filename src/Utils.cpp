#include "Utils.h"
#include <Windows.h>

string Utils::convertIntIntoString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string Utils::readLine() {
    string line = "";
    getline(cin, line);
    return line;
}

string Utils::convertFirstLetterIntoCapitalOtherIntoLowercase(string text) {
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }

    return string(text);
}

string Utils::readNumber(string text, int signPosition) {
    string number = "";

    while (isdigit(text[signPosition]))
    {
        number += text[signPosition];
        signPosition++;
    }
    return number;
}

int Utils::convertStringIntoInt(string number) {
    int Integer;
    istringstream iss(number);
    iss >> Integer;

    return Integer;
}

char Utils::readSign() {
    string line = "";
    char sign = { 0 };

    while (true) { 
        getline(cin, line);

        if (line.length() == 1) {
            sign = line[0];
            break;
        } else {
            if (line != "")
                cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
    }
    return sign;
}

int Utils::readInteger() {
    string line = "";
    int number = 0;

    while (true) {
        getline(cin, line);

        stringstream myStream(line);
        if (myStream >> number)
            break;
        cout << "This is not a number. Enter it once again. " << endl;
    }
    return number;
}
