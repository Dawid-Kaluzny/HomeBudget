#include "ExpensesFile.h"

int ExpensesFile::getLastExpenseId() {
    return lastExpenseId;
}

void ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("EXPENSES");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem("EXPENSEID", expense.getExpenseId());
    xml.AddElem("USERID", expense.getUserId());
    xml.AddElem("DATE", Date::convertDateFromIntToFormattedString(expense.getDate()));
    xml.AddElem("ITEM", expense.getItem());
    xml.AddElem("AMOUNT", AuxiliaryMethods::convertFloatToString(expense.getAmount()));
    lastExpenseId++;

    xml.Save(getFileName());

}

vector <Expense> ExpensesFile::loadExpensesLoggedUserFromFile(int idLoggedUser) {
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;
    int expenseId;
    int userId;
    int date;
    string item;
    float amount;

    xml.Load(getFileName());

    xml.FindElem("EXPENSES");
    xml.IntoElem();
    while (xml.FindElem("EXPENSE")) {
        xml.IntoElem();
        xml.FindElem("EXPENSEID");
        expenseId = atoi(MCD_2PCSZ(xml.GetData()));
        lastExpenseId = expenseId;
        xml.FindElem("USERID");
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (userId == idLoggedUser) {
            xml.FindElem("DATE");
            date = Date::convertDateFromFormattedStringToInt(xml.GetData());
            xml.FindElem("ITEM");
            item = xml.GetData();
            xml.FindElem("AMOUNT");
            amount = atof(MCD_2PCSZ(xml.GetData()));
            expense.setExpenseId(expenseId);
            expense.setUserId(userId);
            expense.setDate(date);
            expense.setItem(item);
            expense.setAmount(amount);
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}
