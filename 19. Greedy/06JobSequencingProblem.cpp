/*
  Job Sequencing Problem :
   -  Objective : Given a set of jobs with deadlines and profits, schedule the jobs to maximize the total profit, ensuring that no two jobs are scheduled at the same time.
   -  Greedy Choice : Select jobs with the highest profit that can be scheduled before their deadline.
  
  
   -  Steps :
     1. Sort jobs in decreasing order of profit.
     2. Iterate through the sorted jobs and place each job in the latest possible time slot before its deadline.
     3. Ensure that no two jobs overlap.

   -  Example :
     - Jobs: (Job1, 4, 100), (Job2, 1, 19), (Job3, 1, 27), (Job4, 1, 25), (Job5, 2, 15)
       - Where (Job, Deadline, Profit)

     - Sorted by Profit: Job1, Job3, Job4, Job2, Job5
     - Schedule: Job1 (deadline 4), Job3 (deadline 3), Job4 (deadline 2), Job2 (deadline 1)
       - Max Profit: 100 + 27 + 25 + 19 = 171
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;     // Job ID
    int deadline; // Deadline by which the job should be finished
    int profit; // Profit of the job
};

// Comparator function to sort jobs by profit in descending order
bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    sort(jobs, jobs + n, cmp);

    vector<int> result(n, -1); // Result array to store the job sequence
    vector<bool> slot(n, false); // Slot availability tracker
    int maxJobs = 0;
    int totalProfit = 0;

    // Iterate over sorted jobs
    for (int i = 0; i < n; ++i) {
        // Find a slot for this job
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                slot[j] = true; // Mark slot as occupied
                result[j] = jobs[i].id; // Assign job to this slot
                totalProfit += jobs[i].profit;
                maxJobs++;
                break;
            }
        }
    }

    // Print the result
    cout << "Job Sequence: ";
    for (int i = 0; i < n; ++i) {
        if (result[i] != -1)
            cout << result[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return result;
}

int main() {
    Job jobs[] = {{1, 4, 100}, {2, 1, 19}, {3, 1, 27}, {4, 1, 25}, {5, 2, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    jobSequencing(jobs, n);

    return 0;
}


/*
Job Sequencing Problem Explanation:

Objective: Schedule jobs to maximize total profit without missing their deadlines.

Algorithm:

Sort Jobs: First, sort jobs based on their profit in descending order.
Find Slots: Iterate through the sorted jobs and place each job in the latest available slot before its deadline.
Update: Mark the slot as occupied and update the total profit and job sequence.
Output: Print the job sequence and total profit.
Example:

Jobs: (1, 4, 100), (2, 1, 19), (3, 1, 27), (4, 1, 25), (5, 2, 15)
Sorted by Profit: (1, 4, 100), (3, 1, 27), (4, 1, 25), (2, 1, 19), (5, 2, 15)
Job Sequence: 1 3 4
Total Profit: 100 + 27 + 25 = 152
*/