#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate M/M/1 queue metrics
void mm1_queue(int lambda, int mu, int n) {
    if (lambda >= mu) {
        cout << "Error: The arrival rate must be less than the service rate to avoid system overload." << endl;
        return;
    }

    double rho = lambda / (double)mu; // Server utilization
    double Lq = pow(rho, 2) / (1 - rho); // Avg no. of customers in the queue
    double Wq = Lq / (double)lambda; // Avg time a customer spends in the queue
    double L = lambda / (double)(mu - lambda); // Avg no. of customers in the system
    double W = 1.0 / (double)(mu - lambda); // Avg time a customer spends in the system
    double P0 = 1 - rho; // Probability of zero jobs in the system
    double Pn = P0 * pow(rho, n); // Probability that 'n' customers are in the system

    // Output the results
    cout << "Rho (Traffic Intensity) = " << rho << endl;
    cout << "Expected Number of Jobs in the Queue (Lq) = " << Lq << endl;
    cout << "Expected Time in the Queue (Wq) = " << Wq << " minutes" << endl;
    cout << "Expected Number of Jobs in the System (L) = " << L << endl;
    cout << "Expected Time in the System (W) = " << W << " minutes" << endl;
    cout << "Probability of Zero Jobs in the System (P0) = " << P0 << endl;
    cout << "Probability of " << n << " Jobs in the System (Pn) = " << Pn << endl;
    cout << "Utilization = " << rho * 100 << "%\n";
}

int main() {
    int lambda, mu, n;
    
    // User input
    cout << "Enter the Arrival Rate (customers per minute): ";
    cin >> lambda;
    cout << "Enter the Service Rate (customers per minute): ";
    cin >> mu;
    cout << "Enter the number of jobs in the system (n): ";
    cin >> n;

    cout << endl;
    mm1_queue(lambda, mu, n);

    return 0;
}
