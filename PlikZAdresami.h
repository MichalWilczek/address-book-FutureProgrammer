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
	const string NAZWA_TYMCZASOWEGO_PLIKU;
	int idOstatniegoAdresata;
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
	
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
	void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);

public:
	PlikZAdresami(string NAZWAPLIKU) : Plik(NAZWAPLIKU), NAZWA_TYMCZASOWEGO_PLIKU("AdresaciTymczasowi.txt") {
		idOstatniegoAdresata = 0;
	};
	int pobierzIdOstatniegoAdresata();
	vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	void dopiszAdresataDoPliku(Adresat adresat);
	void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
	void ustawIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
	void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
};

#endif