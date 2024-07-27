#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start; // Start time of the activity
    int end;   // End time of the activity
};

// Comparator function to sort activities by their end times
bool cmp(Activity a, Activity b) {
    return a.end < b.end;
}

void activitySelection(Activity activities[], int n) {
    // Sort activities by end time
    sort(activities, activities + n, cmp);

    // Select the first activity
    int lastEndTime = activities[0].end;
    cout << "Selected Activities: " << activities[0].start << "-" << activities[0].end;

    // Iterate through the activities
    for (int i = 1; i < n; ++i) {
        if (activities[i].start >= lastEndTime) {
            // If the start time of the current activity is greater than or equal to the end time of the last selected activity
            cout << ", " << activities[i].start << "-" << activities[i].end;
            lastEndTime = activities[i].end; // Update the last end time
        }
    }
    cout << endl;
}

int main() {
    Activity activities[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);
    
    activitySelection(activities, n);

    return 0;
}


/*
Activity Selection Problem Explanation:

Objective: Select the maximum number of non-overlapping activities from a given set of activities.

Algorithm:

Sort Activities: Sort activities based on their end times.
Select Activities: Choose the first activity, then iteratively select the next activity whose start time is greater than or equal to the end time of the last selected activity.
Update: Update the last end time and continue with the selection.


Example:

Activities: (1, 4), (3, 5), (0, 6), (5, 7), (8, 9), (5, 9)
    Sorted by End Time: (1, 4), (3, 5), (5, 7), (8, 9)
    Selected Activities: 1-4, 5-7, 8-9
*/