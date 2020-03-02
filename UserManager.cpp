#include "UserManager.h"

void UserManager::addUser() {
    User user = enterNewRecpientData();

    users.push_back(user);

    cout << endl << "Account successfully created" << endl << endl;
    system("pause");
}

User UserManager::enterNewRecpientData() {
    User user;

    user.setUserId(getNewUserId());

    string login;
    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExists(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Enter name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isLoginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::viewAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getUserId();
        cout << users[i].getLogin();
        cout << users[i].getPassword();
        cout << users[i].getName();
        cout << users[i].getSurname() << endl << endl;
    }
}
