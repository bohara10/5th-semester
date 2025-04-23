#include <stdio.h>
#include <math.h>

int main() {
    // Sample data
    float sample[] = {52, 55, 60, 49, 58};
    int n = sizeof(sample) / sizeof(sample[0]);

    // Confidence level: 95% => Z-score = 1.96
    float z = 1.96;

    // Calculate mean
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += sample[i];
    }
    float mean = sum / n;

    // Calculate standard deviation
    float variance_sum = 0.0;
    for (int i = 0; i < n; i++) {
        variance_sum += pow(sample[i] - mean, 2);
    }
    float stddev = sqrt(variance_sum / (n - 1));  // Sample standard deviation

    // Calculate margin of error
    float margin = z * (stddev / sqrt(n));

    // Calculate confidence interval
    float lower = mean - margin;
    float upper = mean + margin;

    // Output results
    printf("Sample Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stddev);
    printf("95%% Confidence Interval: [%.2f, %.2f]\n", lower, upper);

    return 0;
}
