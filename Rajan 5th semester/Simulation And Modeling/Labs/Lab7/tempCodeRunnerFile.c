#include <stdio.h>

#define N 10  // Number of random numbers

int main() {
    double random_numbers[N] = {0.23, 0.11, 0.87, 0.54, 0.33, 0.66, 0.77, 0.12, 0.98, 0.45};
    int d = 2; // Lag distance
    int i, count = 0;
    double sum = 0.0, mean, variance, R;

    // Compute mean
    for (i = 0; i < N; i++) {
        sum += random_numbers[i];
    }
    mean = sum / N;

    // Compute Auto-correlation coefficient
    sum = 0.0;
    for (i = 0; i < N - d; i++) {
        sum += (random_numbers[i] - mean) * (random_numbers[i + d] - mean);
    }

    // Compute Variance
    double var_sum = 0.0;
    for (i = 0; i < N; i++) {
        var_sum += (random_numbers[i] - mean) * (random_numbers[i] - mean);
    }
    variance = var_sum / N;

    R = sum / ((N - d) * variance);

    printf("Auto-Correlation Coefficient: %lf\n", R);

    return 0;
}
