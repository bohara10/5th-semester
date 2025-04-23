#include <stdio.h>

int main() {
    // Given probabilities
    double P_C_given_C = 0.9;  // Probability of buying Coke given previous purchase was Coke
    double P_C_given_P = 0.2;  // Probability of buying Coke given previous purchase was Pepsi
    double P_P_given_P = 0.8;  // Probability of buying Pepsi given previous purchase was Pepsi

    // Compute probability of purchasing Coke after two purchases
    double P_C_2_given_P_0 = (P_C_given_C * P_C_given_P) + (P_C_given_P * P_P_given_P);

    // Display result
    printf("Probability of purchasing Coke after two purchases: %.2f%%\n", P_C_2_given_P_0 * 100);

    return 0;
}
