#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UsersManager {
	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;
	
	Uzytkownik podajDaneNowegoUzytkownika();
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);

public:
	UsersManager(string nazwaPlikuZUzytkonikami) : plikZUzytkownikami(nazwaPlikuZUzytkonikami) {
		uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
		idZalogowanegoUzytkownika = 0;
	};
	bool czyUzytkownikJestZalogowany();
	int pobierzIdZalogowanegoUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wylogowanieUzytkownika();
};

#endif
