#include <stdio.h>

int main() {
    // Given data
    double lambda = 1.0;  // Arrival rate (customers per minute)
    double mu = 3.0;      // Service rate (customers per minute)
    double service_time = 1.0 / mu; // 20 seconds = 1/3 minutes
    double walking_time = 1.5; // Time to reach the seat (in minutes)

    // Traffic intensity (ρ)
    double rho = lambda / mu;

    // Average waiting time in queue (Wq)
    double Wq = rho / (mu - lambda);

    // Average time spent in the system (Ws)
    double Ws = Wq + service_time;

    // Total time to be seated
    double total_time = Ws + walking_time;

    // Display results
    printf("Average waiting time in queue: %.2f minutes\n", Wq);
    printf("Total time spent in the system: %.2f minutes\n", Ws);
    printf("Total time to be seated: %.2f minutes\n", total_time);

    // Checking if the fan can be seated before kick-off
    double time_before_game = 2.0;
    if (total_time <= time_before_game) {
        printf("Yes, the sports fan can expect to be seated for the kick-off!\n");
    } else {
        printf("No, the sports fan will likely miss the kick-off.\n");
    }

    return 0;
}
