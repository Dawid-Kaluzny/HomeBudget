#include "UserManager.h"

void UserManager::addUser() {
    User user = enterNewRecpientData();

    users.push_back(user);
    usersFile.addUserToFile(user);

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
    name = AuxiliaryMethods::changeFirstLetterToUpperRemainingToLower(name);
    user.setName(name);

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    surname = AuxiliaryMethods::changeFirstLetterToUpperRemainingToLower(surname);
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

int UserManager::loginUser() {
    string login = "", password = "";
    loggedUserId = 0;

    cout << "Enter login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberTries = 3; numberTries > 0; numberTries--) {
                cout << "Enter password. Tries left: " << numberTries << ": ";
                cin >> password;

                if (itr -> getPassword() == password) {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getUserId();
                    return loggedUserId;
                }
            }
            cout << "Incorrect password entered 3 times." << endl;
            system("pause");
            return loggedUserId;
        }
        itr++;
    }
    cout << "There is no user with such login." << endl << endl;
    system("pause");
    return loggedUserId;
}

void UserManager::logOutUser() {
    loggedUserId = 0;
}

void UserManager::changePasswordLoggedUser() {
    string newPassword = "";
    cout << "Enter new password: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedUserId) {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    usersFile.addAllUsersToFile(users);
}

bool UserManager::isUserLogged() {
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getIdLoggedUser() {
    return loggedUserId;
}
