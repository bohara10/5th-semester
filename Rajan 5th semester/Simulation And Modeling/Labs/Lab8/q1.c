#include <stdio.h>

int main() {
    // Sample data
    float sample[] = {52, 55, 60, 49, 58};
    int n = sizeof(sample) / sizeof(sample[0]);

    // Given population mean
    float populationMean = 55.0;

    // Calculate sample mean (point estimate)
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += sample[i];
    }
    float sampleMean = sum / n;

    // Calculate bias
    float bias = sampleMean - populationMean;

    // Output results
    printf("Sample Data: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", sample[i]);
    }

    printf("\nSample Mean (Point Estimate): %.2f\n", sampleMean);
    printf("Population Mean: %.2f\n", populationMean);
    printf("Bias: %.2f\n", bias);

    return 0;
}
