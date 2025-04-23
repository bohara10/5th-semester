#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void JobSequencingWithDeadline(vector<Job> jobs, int n) {
    // Sort jobs by profit in decreasing order
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Create a schedule array, initialized with -1 (indicating free slots)
    vector<int> schedule(maxDeadline + 1, -1);
    int totalProfit = 0, jobCount = 0;

    // Process each job
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;

        // Find a free slot from deadline to 1
        for (int j = min(maxDeadline, deadline); j > 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    // Print selected job sequence
    cout << "\nSelected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != -1) {
            cout << schedule[i] << " ";
        }
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job id, deadline, and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    JobSequencingWithDeadline(jobs, n);

    return 0;
}
