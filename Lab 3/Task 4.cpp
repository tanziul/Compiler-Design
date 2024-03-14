#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isValid(string s) {
    fstream keyword("Keywords.txt");
    string storeWord;
    while (getline(keyword, storeWord)) {
        if (s == storeWord) {
            cout << "Invalid identifier: Keywords/DataType cannot be used as identifiers" << endl;
            keyword.close();
            return false;

        }
    }

    if (s[0] >= '0' && s[0] <= '9') {
        cout << "Invalid identifier: Identifier can't start with a number" << endl;
         keyword.close();
        return false;

    }
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_')) {
        cout << "Invalid identifier: Identifier can't start with a special character except underscore" << endl;
         keyword.close();
        return false;

    }
    for (int i = 0; i < s.length(); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')) {
            cout << "Invalid identifier: Identifier can't contain a special character except underscore" << endl;
             keyword.close();
            return false;

        }
    }
    cout << "Valid identifier" << endl;
     keyword.close();
    return true;

}

int main() {
    fstream keyword("Keywords.txt");
    string s;
    cout << "Enter a string: ";
    cin>>s;

    isValid(s);


    return 0;
}

