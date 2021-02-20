#ifndef ADRESMENEDZER_H
#define ADRESMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresami.h"

using namespace std;

class AdresMenedzer {
	vector <Adresat> adresaci;
	PlikZAdresami plikZAdresami;
	void wyswietlDaneAdresata(Adresat adresat);
	Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

public:
	AdresMenedzer(string nazwaPlikuZAdresami) : plikZAdresami(nazwaPlikuZAdresami) {};
	void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	void dodajAdresata(int idZalogowanegoUzytkownika);
	void wyswietlWszystkichAdresatow();
};

#endif