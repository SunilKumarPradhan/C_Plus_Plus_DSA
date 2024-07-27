#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight; // Weight of the item
    int value;  // Value of the item
    float ratio; // Value-to-weight ratio
};

// Comparator function to sort items by their value-to-weight ratio in descending order
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

float fractionalKnapsack(Item items[], int n, int capacity) {
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; ++i) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    
    // Sort items by value-to-weight ratio
    sort(items, items + n, cmp);

    float totalValue = 0.0;
    int remainingCapacity = capacity;

    // Iterate through the sorted items
    for (int i = 0; i < n; ++i) {
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take the fraction of the item
            totalValue += items[i].value * ((float)remainingCapacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    
    float maxValue = fractionalKnapsack(items, n, capacity);

    cout << "Maximum Value in Knapsack: " << maxValue << endl;

    return 0;
}


/*
Fractional Knapsack Problem Explanation:

Objective: Maximize the total value in a knapsack with a given capacity, allowing for fractional items.

Algorithm:

Calculate Ratio: Compute the value-to-weight ratio for each item.
Sort Items: Sort items based on this ratio in descending order.
Fill Knapsack: Add items to the knapsack, starting with the item having the highest ratio. Take full items if possible; otherwise, take the fractional part of the item if the knapsack is not full.
Output: Calculate and print the maximum value that can be obtained.
Example:

Items: (10, 60), (20, 100), (30, 120)
Ratios: 6.0, 5.0, 4.0
Sorted by Ratio: (10, 60), (20, 100), (30, 120)
Knapsack Capacity: 50
Maximum Value: 60 + 100 + 60 = 220
*/