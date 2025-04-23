#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to be integrated
double f(double x) {
    return sin(x);
}

int main() {
    double a, b;
    int numIterations;

    // Get user input
    cout << "Enter the lower limit of the interval: ";
    cin >> a;
    cout << "Enter the upper limit of the interval: ";
    cin >> b;
    cout << "Enter the number of iterations: ";
    cin >> numIterations;

    // Validate input
    if (a >= b) {
        cout << "Error: Lower limit must be less than the upper limit." << endl;
        return 1;
    }
    if (numIterations <= 0) {
        cout << "Error: Number of iterations must be a positive integer." << endl;
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    int numPointsInside = 0;

    for (int i = 0; i < numIterations; i++) {
        double x = (double) rand() / RAND_MAX * (b - a) + a;
        double y = (double) rand() / RAND_MAX; // sin(x) is at most 1, so max y = 1

        if (y <= f(x)) {
            numPointsInside++;
        }
    }

    // Compute estimated area
    double totalArea = (b - a) * 1.0;
    double areaUnderCurve = totalArea * (double) numPointsInside / numIterations;

    // Output the result
    cout << "Estimated area under the curve: " << areaUnderCurve << endl;

    return 0;
}
