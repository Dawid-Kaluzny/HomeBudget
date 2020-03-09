#include "Date.h"

int Date::getData() {
    string date;
    char choice;

    cin >> choice;

    if(choice == 'y' || choice == 'Y') {
        char bufor[64];
        time_t currentTime;
        time(&currentTime);
        tm currentLocalTime = *localtime(&currentTime);
        strftime(bufor, sizeof(bufor), "%Y%m%d", &currentLocalTime);
        date = bufor;
    } else {
        while(1) {
            string year = "";
            string month = "";
            string day = "";

            cout << "Enter date in format yyyy-mm-dd: ";
            cin >> date;

            if(date.length() == 10 && date[4] == '-' && date[7] == '-') {
                for(int i = 0; i < 10; i++) {
                    if(i < 4)
                        year += date[i];
                    else if (i > 4 && i < 7)
                        month += date[i];
                    else if (i > 7)
                        day += date[i];
                }
                if(isDateCorrect(year, month, day)) {
                    date = "";
                    date = year + month + day;
                    return atoi(date.c_str());
                }
            }
            cout << "You provided the wrong date! Please try again!";
            date = "";
        }
    }
    return atoi(date.c_str());
}

bool Date::isDateCorrect(string year, string month, string day) {
    time_t currentTime;
    int ownYear = atoi(year.c_str());
    int ownMonth = atoi(month.c_str());
    int ownDay = atoi(day.c_str());
    int lastDayInMont = calculateLastDayInMonth(year, month);

    time(&currentTime);
    tm currentLocalTime = *localtime(&currentTime);
    int currentYear = currentLocalTime.tm_year + 1900;
    int currentMonth = currentLocalTime.tm_mon + 1;

    if((ownYear >= 2000 && ownYear < currentYear) && (ownMonth >= 1 && ownMonth <= 12) && (ownDay >= 1 && ownDay <= lastDayInMont)) {
        return true;
    } else if((ownYear == currentYear) && (ownMonth >= 1 && ownMonth <= currentMonth) && (ownDay >= 1 && ownDay <= lastDayInMont)) {
        return true;
    }
    return false;
}

int Date::calculateLastDayInMonth(string year, string month) {
    int lastDayInMonth = 0;
    int ownMonth = atoi(month.c_str());
    int ownYear = atoi(year.c_str());

    switch(ownMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        lastDayInMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        lastDayInMonth = 30;
        break;
    case 2: {
        if (((ownYear % 4 == 0) && (ownYear % 100 != 0)) || (ownYear % 400 == 0))
            lastDayInMonth = 29;
        else
            lastDayInMonth = 28;
    }
    break;
    }
    return lastDayInMonth;
}

string Date::convertDateFromIntToFormattedString(int digital) {
    string formattedString = "";

    formattedString = AuxiliaryMethods::convertIntToString(digital);
    formattedString.insert(4, "-");
    formattedString.insert(7, "-");
    return formattedString;
}

int Date::convertDateFromFormattedStringToInt(string formattedString) {
    int date;

    formattedString.erase(7, 1);
    formattedString.erase(4, 1);
    date = atoi(formattedString.c_str());
    return date;
}
