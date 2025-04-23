#include <iostream>
using namespace std;

void extendedEuclid(int a, int b, int &d, int &x, int &y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
        return;
    }

    int d1, x1, y1;
    extendedEuclid(b, a % b, d1, x1, y1);

    d = d1;
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    int d, x, y;
    extendedEuclid(a, b, d, x, y);

    cout << "GCD: " << d << endl;
    cout << "x: " << x << ", y: " << y << endl;

    return 0;
}
