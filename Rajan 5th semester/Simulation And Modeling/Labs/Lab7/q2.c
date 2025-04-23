#include <stdio.h>

#define N 10  // Number of random numbers

int main() {
    int random_numbers[N] = {123, 456, 789, 222, 333, 777, 888, 999, 111, 555};
    int i, j, k, count[10] = {0};
    int frequency[4] = {0}; // 0: All different, 1: One pair, 2: Three of a kind

    // Count occurrences of digits
    for (i = 0; i < N; i++) {
        int digits[10] = {0};
        int num = random_numbers[i];

        // Count digit occurrences
        while (num > 0) {
            digits[num % 10]++;
            num /= 10;
        }

        // Classify numbers based on repetition
        int pairs = 0, triples = 0;
        for (j = 0; j < 10; j++) {
            if (digits[j] == 2) pairs++;
            if (digits[j] == 3) triples++;
        }

        if (triples == 1) frequency[2]++; // Three of a kind
        else if (pairs == 1) frequency[1]++; // One pair
        else frequency[0]++; // All different
    }

    // Print Results
    printf("Poker Test Results:\n");
    printf("All different: %d times\n", frequency[0]);
    printf("One pair: %d times\n", frequency[1]);
    printf("Three of a kind: %d times\n", frequency[2]);

    return 0;
}
