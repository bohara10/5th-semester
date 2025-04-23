#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10  // Number of sample points

int main() {
    double sample[N] = {0.12, 0.34, 0.56, 0.78, 0.90, 0.23, 0.45, 0.67, 0.89, 0.99};
    double D = 0.0, D_plus, D_minus;
    int i, j;

    // Sorting the sample using Bubble Sort
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (sample[j] > sample[j + 1]) {
                double temp = sample[j];
                sample[j] = sample[j + 1];
                sample[j + 1] = temp;
            }
        }
    }

    // Compute the maximum difference (D-statistic)
    for (i = 0; i < N; i++) {
        double Fn = (i + 1) / (double)N;  // Empirical CDF
        double F_theoretical = sample[i]; // Expected CDF (Uniform[0,1])

        D_plus = fabs(Fn - F_theoretical);
        D_minus = fabs(F_theoretical - i / (double)N);

        if (D_plus > D) D = D_plus;
        if (D_minus > D) D = D_minus;
    }

    // Print the results
    printf("Kolmogorov-Smirnov D-statistic: %lf\n", D);

    // Compute the critical value (for alpha = 0.05, N = 10)
    double D_critical = 1.36 / sqrt(N);

    // Decision Rule
    if (D > D_critical) {
        printf("Reject the null hypothesis (Sample does not follow uniform distribution)\n");
    } else {
        printf("Fail to reject the null hypothesis (Sample follows uniform distribution)\n");
    }

    return 0;
}
