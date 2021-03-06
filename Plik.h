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
	const string NAZWA_PLIKU;
	bool czyPlikJestPusty(fstream& plikTekstowy);

public:
	Plik(string NAZWAPLIKU) : NAZWA_PLIKU(NAZWAPLIKU) {};
};

#endif