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
    cin.ignore();
}

void Budget::logOutUser() {
    userManager.logOutUser();
    delete balanceManager;
    balanceManager = NULL;
}

void Budget::changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
    cin.ignore();
}

bool Budget::isUserLogged() {
    return userManager.isUserLogged();
}

void Budget::addIncome() {
    balanceManager -> addIncome();
    cin.ignore();
}

void Budget::addExpense() {
    balanceManager -> addExpense();
    cin.ignore();
}

void Budget::viewBalanceFromCurrentMonth() {
    balanceManager -> viewBalanceFromCurrentMonth();
}

void Budget::viewBalanceFromPreviousMonth() {
    balanceManager -> viewBalanceFromPreviousMonth();
}

void Budget::viewBalanceFromSelectedPeriod() {
    balanceManager -> viewBalanceFromSelectedPeriod();
    cin.ignore();
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
    cout << "3. Balance from the current month" << endl;
    cout << "4. Balance from the previous month" << endl;
    cout << "5. Balance from the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
