#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "Date.h"
#include "Expense.h"
#include "XmlFile.h"

using namespace std;

class ExpensesFile : public XmlFile {
    int lastExpenseId;
public:
    ExpensesFile(string expensesFileName) : XmlFile(expensesFileName) {
        lastExpenseId = 0;
    };
    int getLastExpenseId();
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesLoggedUserFromFile(int idLoggedUser);

};

#endif
