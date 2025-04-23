#include <stdio.h>

int main() {
    // Given probabilities
    double P_N_given_N = 0.8;  // Probability of no rain tomorrow if no rain today
    double P_R_given_N = 0.2;  // Probability of rain tomorrow if no rain today
    double P_N_given_R = 0.6;  // Probability of no rain tomorrow if rain today
    double P_R_given_R = 0.4;  // Probability of rain tomorrow if rain today

    // Compute probability of no rain on the day after tomorrow
    double P_N_day2_given_N_day0 = (P_N_given_N * P_N_given_N) + (P_N_given_R * P_R_given_N);

    // Display result
    printf("Probability of no rain the day after tomorrow given no rain today: %.2f%%\n", P_N_day2_given_N_day0 * 100);

    return 0;
}
