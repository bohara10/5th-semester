#include <stdio.h>

int main() {
    // Given parameters
    int X = 11;  // Seed value
    int a = 5;   // Multiplier
    int c = 13;  // Increment
    int m = 100; // Modulus
    int i;

    // Generate 50 random numbers
    printf("Generated random numbers:\n");
    for(i = 0; i < 50; i++) {
        X = (a * X + c) % m;  // LCG formula
        printf("%d ", X);
    }

    printf("\n");
    return 0;
}
