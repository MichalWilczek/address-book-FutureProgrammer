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

void KsiazkaAdresowa::usunAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresMenedzer->usunAdresata();
    }
    else {
        cout << "Aby usunac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresMenedzer->edytujAdresata();
    }
    else {
        cout << "Aby edytowac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::run() {
    char wybor = { 0 };

    while (true) {
        if (!uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                dodajAdresata();
                break;
            /*
            case '2':
                cout << "Not implemented" << endl;
                Sleep(2000);
                break;
            case '3':
                cout << "Not implemented" << endl;
                Sleep(2000);
                break;
            */
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogowanieUzytkownika();
                break;
            }
        }
    }
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor = { 0 };

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor = { 0 };

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
    //cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
