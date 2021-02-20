#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {
public:
	static string konwersjaIntNaString(int liczba);
	static int konwersjaStringNaInt(string liczba);
	static string wczytajLinie();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
	static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
