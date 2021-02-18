#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {
	int idZalogowanegoUzytkownika;
	vector <Uzytkownik> uzytkownicy;
	PlikZUzytkownikami plikZUzytkownikami;
	
	Uzytkownik podajDaneNowegoUzytkownika();
	int pobierzIdNowegoUzytkownika();
	bool czyIstniejeLogin(string login);

public:
	UzytkownikMenedzer(string nazwaPlikuZUzytkonikami) : plikZUzytkownikami(nazwaPlikuZUzytkonikami) {};
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wczytajUzytkownikowZPliku();
};

#endif
