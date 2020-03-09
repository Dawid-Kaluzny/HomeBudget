#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "Date.h"
#include "Income.h"
#include "XmlFile.h"

using namespace std;

class IncomesFile : public XmlFile {
    int lastIncomeId;
public:
    IncomesFile(string incomesFileName) : XmlFile(incomesFileName) {
        lastIncomeId = 0;
    };
    int getLastIncomeId();
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesLoggedUserFromFile(int idLoggedUser);

};

#endif
