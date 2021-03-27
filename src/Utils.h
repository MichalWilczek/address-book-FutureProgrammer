#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Utils {
public:
	static string convertIntIntoString(int number);
	static int convertStringIntoInt(string number);
	static string readLine();
	static string convertFirstLetterIntoCapitalOtherIntoLowercase(string text);
    static string readNumber(string text, int signPosition);
	static char readSign();
	static int readInteger();
};

#endif
