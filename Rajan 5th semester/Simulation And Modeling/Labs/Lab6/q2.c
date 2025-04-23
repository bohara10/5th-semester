#include <stdio.h>

int main() {
    // Given parameters
    int X = 13;   // Seed value
    int a = 15;   // Multiplier
    int m = 1000; // Modulus
    int i;

    // Generate 50 random numbers
    printf("Generated random numbers:\n");
    for(i = 0; i < 50; i++) {
        X = (a * X) % m;  // Multiplicative Congruential Formula
        printf("%d ", X);
    }

    printf("\n");
    return 0;
}
