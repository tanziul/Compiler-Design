#include <iostream>
#include<stack>
using namespace std;

int main() {
    string firstName, lastName;
    stack<char> nameStack;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;


    for (char ch : firstName) {
        nameStack.push(ch);
    }

    nameStack.push(' ');


    for (char ch : lastName) {
        nameStack.push(ch);
    }

    string fullName;
    while (!nameStack.empty()) {
        fullName = nameStack.top()+fullName ;
        nameStack.pop();
    }

    cout << "Full name: " << fullName << endl;

    return 0;
}



