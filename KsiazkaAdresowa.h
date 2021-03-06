#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <string>
#include "UzytkownikMenedzer.h"
#include "AdresMenedzer.h"
#include "MetodyPomocnicze.h"
using namespace std;

class KsiazkaAdresowa {
	UzytkownikMenedzer uzytkownikMenedzer;
	AdresMenedzer *adresMenedzer;
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	
	char wybierzOpcjeZMenuGlownego();
	char wybierzOpcjeZMenuUzytkownika();

public:
	KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
		uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
		adresMenedzer = NULL;
	};
	~KsiazkaAdresowa() {
		delete adresMenedzer;
		adresMenedzer = NULL;
	}

	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
	void run();
};

#endif
