#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int total_points, points_inside_circle = 0;
    double x, y, pi_estimate;

    // Ask for the total number of points
    printf("Enter the total number of points: ");
    scanf("%d", &total_points);

    // Validate input
    if (total_points <= 0) {
        printf("Total points must be a positive integer.\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < total_points; i++) {
        // Generate random points in the range [0, 1]
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        // Check if the point is inside the unit circle
        if (x * x + y * y <= 1.0) {
            points_inside_circle++;
        }
    }

    // Calculate the estimated value of PI
    pi_estimate = 4.0 * points_inside_circle / total_points;
    printf("Estimated value of PI: %f\n", pi_estimate);

    return 0;
}
