#include <iostream>
#include "ContactBook.h"

using namespace std;

int main()
{
    ContactBook contactsBook("Uzytkownicy.txt", "Adresaci.txt");
    contactsBook.run();
    
    return 0;
}