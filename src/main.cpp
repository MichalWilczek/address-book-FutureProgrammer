#include <iostream>
#include "ContactBook.h"

using namespace std;

int main()
{
    ContactBook contactsBook("Users.txt", "Contacts.txt");
    contactsBook.run();
    
    return 0;
}