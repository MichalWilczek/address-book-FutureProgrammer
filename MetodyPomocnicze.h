#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctype.h>

using namespace std;

class MetodyPomocnicze {
public:
	static string konwersjaIntNaString(int liczba);
	static int konwersjaStringNaInt(string liczba);
	static string wczytajLinie();
	static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
};

#endif
