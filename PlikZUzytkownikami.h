#ifndef PLIKZUZYTKOWNIKAMI_h
#define PLIKZUZYTKOWNIKAMI_h


#include <iostream>
#include <vector>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami {
	string nazwaPlikuZUzytkownikami;
	fstream plikTekstowy;
	bool czyPlikJestPusty();
	string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
	PlikZUzytkownikami();
	void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
