#include <stdio.h>
#include <math.h>

#define N 10  // Number of random numbers
#define K 5   // Number of bins

int main() {
    double random_numbers[N] = {0.12, 0.34, 0.56, 0.78, 0.90, 0.23, 0.45, 0.67, 0.89, 0.99};
    int observed[K] = {0};
    int i, bin;
    double expected = N / (double)K; // Expected frequency per bin
    double chi_square = 0.0;

    // Count observed frequencies
    for (i = 0; i < N; i++) {
        bin = (int)(random_numbers[i] * K); // Assign bin (0 to K-1)
        observed[bin]++;
    }

    // Compute Chi-Square Statistic
    for (i = 0; i < K; i++) {
        chi_square += ((observed[i] - expected) * (observed[i] - expected)) / expected;
    }

    // Print Results
    printf("Chi-Square Test Statistic: %lf\n", chi_square);

    return 0;
}
 