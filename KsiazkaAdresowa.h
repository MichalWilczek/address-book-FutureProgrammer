#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresMenedzer.h"
using namespace std;

class KsiazkaAdresowa {
	UzytkownikMenedzer uzytkownikMenedzer;
	AdresMenedzer adresMenedzer;

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : 
		uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresMenedzer(nazwaPlikuZAdresatami) {
		uzytkownikMenedzer.wczytajUzytkownikowZPliku();
	};
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
};

#endif
