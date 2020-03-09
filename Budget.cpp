#include "Budget.h"

void Budget::addUser() {
    userManager.addUser();
    cin.ignore();
}

void Budget::loginUser() {
    userManager.loginUser();
    if(userManager.isUserLogged()) {
        balanceManager = new BalanceManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getIdLoggedUser());
    }
}

void Budget::logOutUser() {
    userManager.logOutUser();
    delete balanceManager;
    balanceManager = NULL;
}

void Budget::changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
}

bool Budget::isUserLogged() {
    return userManager.isUserLogged();
}

void Budget::addIncome()
{
   balanceManager -> addIncome();
}

void Budget::addExpense()
{
   balanceManager -> addExpense();
}

char Budget::selectOptionsMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Sign in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char Budget::selectOptionsUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

void Budget::viewAllIncomes()
{
   balanceManager -> viewAllIncomes();
}

