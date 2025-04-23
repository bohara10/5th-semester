#include <stdio.h>
#include <math.h>

int main() {
    double lambda = 1.0 / 10.0; // Mean inter-arrival rate (customers per minute)
    double mu = 1.0 / 5.0; // Service rate (customers per minute)

    // Probability that a customer will not have to wait at the counter (P0)
    double rho = lambda / mu;
    double P0 = 1.0 - rho;  

    // Expected number of customers in the bank (L)
    if (mu - lambda <= 0) {
        printf("Error: The service rate must be greater than the arrival rate to avoid system overload.\n");
        return 1;
    }

    double L = lambda / (mu - lambda);

    // Average time a customer can expect to spend in the bank (W)
    double W = 1.0 / (mu - lambda);

    // Print results
    printf("Probability that a customer will not have to wait: %lf\n", P0);
    printf("Expected number of customers in the bank: %lf\n", L);
    printf("Average time a customer can expect to spend in the bank: %lf minutes\n", W);

    return 0;
}
