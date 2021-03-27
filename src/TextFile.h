#ifndef TEXTFILE_h
#define TEXTFILE_h

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"

using namespace std;

class TextFile {
protected:
	const string FILENAME;
	bool isFileEmpty(fstream& textFile);

public:
	TextFile(string FILENAME) : FILENAME(FILENAME) {};
	static void deleteFile(string filenameWithExtension);
	static void changeFilename(string oldName, string newName);
};

#endif