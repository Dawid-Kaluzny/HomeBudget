#include "BalanceManager.h"

void BalanceManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterDataNewIncome();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
    system("pause");
}

Income BalanceManager::enterDataNewIncome() {
    Income income;
    int date;
    string item;
    float amount;

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    cout << "Is the Income today? [y/n]: ";
    date = Date::getData();
    cin.ignore();

    cout << "What is the Income?: ";
    getline(cin, item);

    cout << "Enter the Amount of Income: ";
    amount = income.enterFinanceAmount();

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void BalanceManager::viewAllIncomes() {
    for(int i= 0; i <incomes.size(); i++) {
        cout << incomes[i].getIncomeId() << " ";
        cout << incomes[i].getUserId() << " ";
        cout << incomes[i].getDate() << " ";
        cout << incomes[i].getItem() << " ";
        cout << incomes[i].getAmount() << endl;
    }
    system("pause");
}
