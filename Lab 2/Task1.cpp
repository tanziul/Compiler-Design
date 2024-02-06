#include <iostream>
#include <string>
using namespace std;

void result() {
    string n;
    cout << "Enter a value: ";
    cin >> n;

    bool numeric = true;
    bool hasDecimal = false;


    if (n.empty()) {
        numeric = false;
    }
    else {

        for (int i = 0; i < n.size(); ++i) {

            if (n[i] >= '0' && n[i] <= '9') {
                continue;
            }

            else if (i == 0 && n[i] == '-') {
                continue;
            }

            else if (n[i] == '.' && !hasDecimal) {
                hasDecimal = true;
                continue;
            }
            else {
                numeric = false;
                break;
            }
        }
    }

    if (numeric) {
        cout << "Numeric constant" << endl;
    }

     else {
        cout << "Not numeric" << endl;
    }
}

int main() {
    result();
    return 0;
}

