#include <iostream>
#include <string>
using namespace std;

void result() {
    string s;
    cin >> s;

    if (s[0] == '/' && s[1] == '/') {
        cout << "single line comment" << endl;
    } else if (s[0] == '/' && s[1] == '*') {
        bool multiline = false;
        while (cin >> s) {
            if (s.size() >= 2 && s[s.size() - 2] == '*' && s[s.size() - 1] == '/') {
                multiline = true;
                break;
            }
        }
        if (multiline) {
            cout << "multiple line comment" << endl;
        } else {
            cout << "not comment line" << endl;
        }
    } else {
        cout << "not comment line" << endl;
    }
}

int main() {
    result();
    return 0;
}
