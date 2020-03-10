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

void BalanceManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = enterDataNewExpense();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
    system("pause");
}

Expense BalanceManager::enterDataNewExpense() {
    Expense expense;
    int date;
    string item;
    float amount;

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    cout << "Is the Expense today? [y/n]: ";
    date = Date::getData();
    cin.ignore();

    cout << "What is the Expense?: ";
    getline(cin, item);

    cout << "Enter the Amount of Expense: ";
    amount = expense.enterFinanceAmount();

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

void BalanceManager::viewBalanceFromCurrentMonth() {
    string earliestDate = "";
    string currentMonth = "";
    string currentYear = "";
    int earliestDateCurrentMonth = 0;
    int latestDateCurrentMonth = 0;
    char bufor[64];
    time_t currentTime;

    time(&currentTime);
    tm currentLocalTime = *localtime(&currentTime);
    strftime(bufor, sizeof(bufor), "%Y%m01", &currentLocalTime);
    earliestDate = bufor;
    earliestDateCurrentMonth = atoi(earliestDate.c_str());
    strftime(bufor, sizeof(bufor), "%Y", &currentLocalTime);
    currentYear = bufor;
    strftime(bufor, sizeof(bufor), "%m", &currentLocalTime);
    currentMonth = bufor;
    latestDateCurrentMonth = earliestDateCurrentMonth - 1 + Date::calculateLastDayInMonth(currentYear, currentMonth);

    viewBalance(earliestDateCurrentMonth, latestDateCurrentMonth);
}

void BalanceManager::viewBalance(int earliestDate, int latestDate) {
    float incomesSum = 0;
    float expensesSum = 0;

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());
    system("cls");
    cout << "INCOMES" << endl;

    for (vector<Income>::iterator itr = incomes.begin(), koniec = incomes.end(); itr != koniec; ++itr) {
        if (earliestDate <= itr -> getDate() && latestDate >= itr -> getDate()) {
            cout << Date::convertDateFromIntToFormattedString(itr -> getDate()) << " ";
            cout << itr -> getAmount() << " ";
            cout << itr -> getItem() << endl;
            incomesSum += itr -> getAmount();
        }
    }
    cout << endl << "EXPENSES" << endl;

    for (vector<Expense>::iterator itr = expenses.begin(), koniec = expenses.end(); itr != koniec; ++itr) {
        if (earliestDate <= itr -> getDate() && latestDate >= itr -> getDate()) {
            cout << Date::convertDateFromIntToFormattedString(itr -> getDate()) << " ";
            cout << itr -> getAmount() << " ";
            cout << itr -> getItem() << endl;
            expensesSum += itr -> getAmount();
        }
    }

    cout << endl << "INCOMES SUM: " << incomesSum << endl;
    cout << "EXPENSES SUM: " << expensesSum << endl;
    cout << "SAVINGS: " << incomesSum - expensesSum << endl << endl;
    system("pause");
}

void BalanceManager::viewBalanceFromPreviousMonth() {
    string earliestDate = "";
    string previousMonth = "";
    string year = "";
    int earliestDatePreviousMonth = 0;
    int latestDatePreviousMonth = 0;
    char bufor[64];
    time_t currentTime;

    time(&currentTime);
    tm currentLocalTime = *localtime(&currentTime);
    if (currentLocalTime.tm_mon == 0) {
        currentLocalTime.tm_mon = 11;
        currentLocalTime.tm_year -= 1;
    } else {
        currentLocalTime.tm_mon -= 1;
    }
    strftime(bufor, sizeof(bufor), "%Y%m01", &currentLocalTime);
    earliestDate = bufor;
    earliestDatePreviousMonth = atoi(earliestDate.c_str());
    strftime(bufor, sizeof(bufor), "%Y", &currentLocalTime);
    year = bufor;
    strftime(bufor, sizeof(bufor), "%m", &currentLocalTime);
    previousMonth = bufor;
    latestDatePreviousMonth = earliestDatePreviousMonth - 1 + Date::calculateLastDayInMonth(year, previousMonth);

    viewBalance(earliestDatePreviousMonth, latestDatePreviousMonth);
}
