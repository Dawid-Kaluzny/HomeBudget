#include "AuxiliaryMethods.h"

string AuxiliaryMethods::changeFirstLetterToUpperRemainingToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::loadCharacter() {
    string text = "";
    char character  = {0};

    while (true) {
        getline(cin, text);

        if (text.length() == 1) {
            character = text[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return character;
}

string AuxiliaryMethods::convertIntToString(int digital) {
    ostringstream ss;
    ss << digital;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatToString(float digitalFloat) {
    ostringstream ss;
    ss << digitalFloat;
    string str(ss.str());
    return str;
}
