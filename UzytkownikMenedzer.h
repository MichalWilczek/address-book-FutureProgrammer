#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikMenedzer {
	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;
	
	Uzytkownik podajDaneNowegoUzytkownika();
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);

public:
	UzytkownikMenedzer(string nazwaPlikuZUzytkonikami) : plikZUzytkownikami(nazwaPlikuZUzytkonikami) {
		idZalogowanegoUzytkownika = 0;
	};
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void wylogowanieUzytkonika();
	void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
