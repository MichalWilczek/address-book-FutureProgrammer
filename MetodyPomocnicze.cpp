#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwersjaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}