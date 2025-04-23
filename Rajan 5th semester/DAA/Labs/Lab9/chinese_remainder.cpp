#include <iostream>
#include <vector>

using namespace std;

// Function to compute the modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;

        t = m;
        m = a % m, a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to apply the Chinese Remainder Theorem
int chineseRemainder(const vector<int>& nums, const vector<int>& rems) {
    int prod = 1;
    int result = 0;

    for (int num : nums)
        prod *= num;

    for (int i = 0; i < nums.size(); i++) {
        int pp = prod / nums[i];
        int inv = modInverse(pp, nums[i]);
        result += rems[i] * inv * pp;
    }

    return result % prod;
}

int main() {
    int k;
    cout << "Enter number of congruences: ";
    cin >> k;

    vector<int> nums(k), rems(k);
    cout << "Enter the moduli (pairwise coprime):\n";
    for (int i = 0; i < k; i++) {
        cout << "n[" << i + 1 << "]: ";
        cin >> nums[i];
    }

    cout << "Enter the remainders:\n";
    for (int i = 0; i < k; i++) {
        cout << "a[" << i + 1 << "]: ";
        cin >> rems[i];
    }

    int result = chineseRemainder(nums, rems);
    cout << "The solution x is: " << result << endl;

    return 0;
}
