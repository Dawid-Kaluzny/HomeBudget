#include "IncomesFile.h"

int IncomesFile::getLastIncomeId() {
    return lastIncomeId;
}

void IncomesFile::addIncomeToFile(Income income) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("INCOMES");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeId());
    xml.AddElem("USERID", income.getUserId());
    xml.AddElem("DATE", Date::convertDateFromIntToFormattedString(income.getDate()));
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", AuxiliaryMethods::convertFloatToString(income.getAmount()));
    lastIncomeId++;

    xml.Save(getFileName());

}

vector <Income> IncomesFile::loadIncomesLoggedUserFromFile(int idLoggedUser) {
    Income income;
    vector <Income> incomes;
    CMarkup xml;
    int incomeId;
    int userId;
    int date;
    string item;
    float amount;

    xml.Load(getFileName());

    xml.FindElem("INCOMES");
    xml.IntoElem();
    while (xml.FindElem("INCOME")) {
        xml.IntoElem();
        xml.FindElem("INCOMEID");
        incomeId = atoi(MCD_2PCSZ(xml.GetData()));
        lastIncomeId = incomeId;
        xml.FindElem("USERID");
        userId = atoi(MCD_2PCSZ(xml.GetData()));
        if (userId == idLoggedUser) {
            xml.FindElem("DATE");
            date = Date::convertDateFromFormattedStringToInt(xml.GetData());
            xml.FindElem("ITEM");
            item = xml.GetData();
            xml.FindElem("AMOUNT");
            amount = atof(MCD_2PCSZ(xml.GetData()));
            income.setIncomeId(incomeId);
            income.setUserId(userId);
            income.setDate(date);
            income.setItem(item);
            income.setAmount(amount);
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}
