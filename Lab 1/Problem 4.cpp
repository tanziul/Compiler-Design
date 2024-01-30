#include <iostream>
using namespace std;
void myfac()
{
    int n, i, j = 0, factorial = 1;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "\nError!! Factorial is not defined for negative numbers." << endl;
    } else {
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                j++;
            }
        }

        if (j == 0) {
            for (i = 2; i <= n; i++) {
                factorial = factorial * i;
            }
            cout << "\nFactorial of " << n << " is " << factorial << endl;
        } else {
            cout << "\nError!! " << n << " is not a prime number" << endl;
        }
    }
    cout << endl;
}

int main()
{
    myfac();
    return 0;
}

