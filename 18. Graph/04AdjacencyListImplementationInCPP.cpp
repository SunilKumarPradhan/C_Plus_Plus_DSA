#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Remove this line if the graph is directed
}

/*
Each line represents a node and its connections. Here's how to interpret it:

The number before the colon (:) is the node we're looking at.
The numbers after the colon are the nodes that are directly connected to this node.

For example, let's take a few lines from the output:

0: 1 2 3 4
1: 0 5 6
5: 1 13 7

Here's how to read these:

- 0: 1 2 3 4 means that node 0 is connected to nodes 1, 2, 3, and- 4.
- 1: 0 5 6 means that node 1 is connected to nodes 0, 5, and 6.
- 5: 1 13 7 means that node 5 is connected to nodes 1, 13, and 7.

Some key points to remember:

This is an undirected graph, so if node A is connected to node B, node B will also be connected to node A.
The order of the connections doesn't matter. 1: 0 5 6 and 1: 6 0 5 represent the same connections.
If a node has no connections, it would appear as just the node number followed by a colon with nothing after it.

*/
int main() {
    int size = 5;  // Define the correct size of the graph
    vector<int> adj[size];

    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 0);

    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    return 0;
}


// Another way of representation as it goes , this follows like python:: 

/*
   
    int V = 5;

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}
    };

    vector<vector<int>> adjList(V);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Remove this line if the graph is directed
    }


    cout << "Adjacency List Representation:\n";
  
    // for (int i = 0; i < V; ++i) {
    //     cout << i << ": ";
    //     for (int j : adjList[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    //THIS IS BETTER AND FASTER LOOP ARRANGEMENT
    for (auto i = 0; i < V; ++i) {
        cout << i << ": ";
       
        for ( auto j : adjList[i])
             cout << j << " ";
       
        cout << endl;
    }

    return 0;
}


*/

// Most easiest way of adjacency list

/*
int main() {
    // Number of vertices
    int V = 5;
    
    // Adjacency list representation using initializer lists
    vector<vector<int>> adjList = {
        {1, 2},       // Neighbors of vertex 0
        {0, 2},       // Neighbors of vertex 1
        {0, 1, 3},    // Neighbors of vertex 2
        {2, 4},       // Neighbors of vertex 3
        {3}           // Neighbors of vertex 4
    };

    // Printing the adjacency list
    cout << "Adjacency List Representation:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}⁡
*/