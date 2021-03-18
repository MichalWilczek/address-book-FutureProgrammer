#ifndef ADRESMENEDZER_H
#define ADRESMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresami.h"

using namespace std;

class AdresMenedzer {
	const int ID_ZALOGOWANEGO_UZYKOWNIKA;	
	vector <Adresat> adresaci;
	PlikZAdresami plikZAdresami;

	void wyswietlDaneAdresata(Adresat adresat);
	Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
	int podajIdWybranegoAdresata();
	static void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
	char wybierzOpcjeZMenuEdycja();

public:
	AdresMenedzer(string nazwaPlikuZAdresami, int idZalogowanegoUzytkownika)
		: plikZAdresami(nazwaPlikuZAdresami), ID_ZALOGOWANEGO_UZYKOWNIKA(idZalogowanegoUzytkownika) {
		adresaci = plikZAdresami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYKOWNIKA);
	};
	void dodajAdresata(int idZalogowanegoUzytkownika);
	void usunAdresata();
	void edytujAdresata();
	void wyswietlWszystkichAdresatow();
	void wyszukajAdresatowPoImieniu();
	void wyszukajAdresatowPoNazwisku();
};

#endif