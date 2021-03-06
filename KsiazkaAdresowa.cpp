#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
	uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
	uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
	uzytkownikMenedzer.logowanieUzytkownika();
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresMenedzer = new AdresMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
	}
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
	uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
	uzytkownikMenedzer.wylogowanieUzytkownika();
	delete adresMenedzer;
	adresMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata() {
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresMenedzer->dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
	} else {
		cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
		adresMenedzer->wyswietlWszystkichAdresatow();
	}
	else {
		cout << "Aby wyswietlic adesatow, nalezy najpierw sie zalogowac" << endl;
		system("pause");
	}
}
