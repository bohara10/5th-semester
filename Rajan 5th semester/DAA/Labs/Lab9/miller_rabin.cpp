#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to perform modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp & 1)
            result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }

    return result;
}

// Function to perform one iteration of the Miller-Rabin test
bool millerTest(long long d, long long n) {
    long long a = 2 + rand() % (n - 4); // Pick a random base in [2, n-2]
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (__int128)x * x % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}

// Miller-Rabin primality test
bool isPrime(long long n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main() {
    srand(time(0)); // Seed for randomness

    long long n;
    int k = 5; // Number of iterations

    cout << "Enter a number to check for primality: ";
    cin >> n;

    if (isPrime(n, k))
        cout << n << " is probably prime." << endl;
    else
        cout << n << " is composite." << endl;

    return 0;
}
