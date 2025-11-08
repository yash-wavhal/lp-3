#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string job_id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs) {
    // Step 1: Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find maximum deadline
    int max_deadline = 0;
    for (auto &job : jobs)
        max_deadline = max(max_deadline, job.deadline);

    // Step 3: Initialize time slots (empty = "")
    vector<string> slots(max_deadline + 1, "");
    int total_profit = 0;

    // Step 4: Assign jobs to slots
    for (auto &job : jobs) {
        for (int slot = job.deadline; slot > 0; slot--) {
            if (slots[slot] == "") {
                slots[slot] = job.job_id;
                total_profit += job.profit;
                break;
            }
        }
    }

    // Display result
    cout << "Scheduled Jobs: [ ";
    for (int i = 1; i <= max_deadline; i++) {
        if (slots[i] != "")
            cout << "'" << slots[i] << "' ";
    }
    cout << "]" << endl;

    cout << "Total Profit: " << total_profit << endl;
}

int main() {
    vector<Job> jobs = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };

    jobSequencing(jobs);

    return 0;
}


//user input
int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job details (JobID Deadline Profit):\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].job_id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs);

    return 0;
}
