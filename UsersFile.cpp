#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("USERS");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("USERID", user.getUserId());
    xml.AddElem("LOGIN", user.getLogin());
    xml.AddElem("PASSWORD", user.getPassword());
    xml.AddElem("NAME", user.getName());
    xml.AddElem("SURNAME", user.getSurname());

    xml.Save("users.xml");
}

vector <User> UsersFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;
    int userId;
    string login;
    string password;
    string name;
    string surname;

    xml.Load(getFileName());

    xml.FindElem("USERS");
    xml.IntoElem();
    while (xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("USERID");
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        user.setUserId(userId);
        xml.FindElem("LOGIN");
        login = xml.GetData();
        user.setLogin(login);
        xml.FindElem("PASSWORD");
        password = xml.GetData();
        user.setPassword(password);
        xml.FindElem("NAME");
        name = xml.GetData();
        user.setName(name);
        xml.FindElem("SURNAME");
        surname = xml.GetData();
        user.setSurname(surname);
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}
