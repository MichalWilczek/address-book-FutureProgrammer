#ifndef PLIKZADRESAMI_h
#define PLIKZADRESAMI_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Plik.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresami :public Plik {
	int idOstatniegoAdresata;
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:
	PlikZAdresami(string NAZWAPLIKU) : Plik(NAZWAPLIKU) {
		idOstatniegoAdresata = 0;
	};
	int ustawNoweIdOstatniegoAdresata();
	vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	void dopiszAdresataDoPliku(Adresat adresat);
};

#endif