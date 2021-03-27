#include "UsersManager.h"


void UsersManager::registerUser() {
    User uzytkownik = getUserNew();

    users.push_back(uzytkownik);
    textFileUsers.addUserToFile(uzytkownik);

    cout << endl << "Account created." << endl << endl;
    system("pause");
}

int UsersManager::getIdUserLoggedIn() {
    if (idUserLoggedIn > 0)
        return idUserLoggedIn;
    else
        throw invalid_argument("Received value is lower than 1.");
}

void UsersManager::showUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getIdContact() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

User UsersManager::getUserNew() {
    User user;

    user.setIdContact(getUserIdNew());

    string login;
    do {
        cout << "Set login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Set password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

bool UsersManager::isUserLoggedIn() {
    if (idUserLoggedIn > 0) return true;
    else return false;
}

int UsersManager::getUserIdNew() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getIdContact() + 1;
}

bool UsersManager::doesLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "User with such login already exists in the database." << endl;
            return true;
        }
    }
    return false;
}

void UsersManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Set login: ";
    login = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int trials = 3; trials > 0; trials--)
            {
                cout << "Set password. Remaining trials: " << trials << ": ";
                password = Utils::readLine();

                if (itr->getPassword() == password)
                {
                    cout << endl << "Login successful." << endl << endl;
                    system("pause");
                    idUserLoggedIn = itr->getIdContact();
                    return;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "The user witch such login does not exist in the databse." << endl << endl;
    system("pause");
    return;
}

void UsersManager::changePasswordLoggedInUser()
{
    string newPassword = "";
    cout << "Set new password: ";
    newPassword = Utils::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getIdContact() == idUserLoggedIn)
        {
            itr->setPassword(newPassword);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
    textFileUsers.saveUsersToFile(users);
}

void UsersManager::logOutUser() {
    idUserLoggedIn = 0;
}