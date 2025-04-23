#include <iostream>
using namespace std;

int gcd(int a, int b, int &stepCount) {
    stepCount++;
    if (b == 0) return a;
    return gcd(b, a % b, stepCount);
}

int main() {
    int num1, num2, stepCount = 0;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "GCD: " << gcd(num1, num2, stepCount) << endl;
    cout << "Steps required: " << stepCount << endl;
    return 0;
}
