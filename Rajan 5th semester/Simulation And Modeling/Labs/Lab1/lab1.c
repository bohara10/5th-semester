#include <stdio.h>

int main() {
    // Given Data
    double Y_prev = 80; // Initial value of Y-1
    double G[5] = {20, 25, 30, 35, 40}; // Governmental expenditure for 5 years
    double I, Y, T, C;

    printf("Year\tInvestment (I)\tIncome (Y)\tTaxes (T)\tConsumption (C)\n");

    for (int year = 0; year < 5; year++) {
        I = 2 + 0.1 * Y_prev; // Investment equation
        Y = 45.45 + 2.27 * (I + G[year]); // National income equation
        T = 0.2 * Y; // Tax equation
        C = 20 + 0.7 * (Y - T); // Consumption equation

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", year + 1, I, Y, T, C);

        Y_prev = Y; // Update Y-1 for next year
    }

    return 0;
}
