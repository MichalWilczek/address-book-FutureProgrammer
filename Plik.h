#ifndef PLIK_h
#define PLIK_h

#include <iostream>
#include <vector>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class Plik {
protected:
	const string nazwaPliku;
	bool czyPlikJestPusty();

public:
	Plik(string NAZWAPLIKU) : nazwaPliku(NAZWAPLIKU) {};
};

#endif