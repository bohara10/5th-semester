#include<stdio.h>
#include <math.h>
#include <stdlib.h>

double poisson(int x, double lambda) {
return exp(-lambda) * pow(lambda, x) / tgamma(x + 1);
}
int main() {
double lambda = 12.0; // average arrival rate per hour
printf("Poisson Distribution for x = 0 to 15:\n");
for (int x = 0; x<= 15; x++) {
double probability = poisson(x, lambda);
printf("P(X = %d) = %f\n", x, probability);
}
return 0;
}