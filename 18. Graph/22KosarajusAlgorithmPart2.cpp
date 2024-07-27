#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void DFS(vector<int> adj[], int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            DFS(adj, i, visited, Stack);
    Stack.push(v);
}

void fillOrder(vector<int> adj[], int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            fillOrder(adj, i, visited, Stack);
    Stack.push(v);
}

void DFSUtil(vector<int> adj[], int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";
    for (int i : adj[v])
        if (!visited[i])
            DFSUtil(adj, i, visited);
}

void findSCCs(vector<int> adj[], int size) {
    stack<int> Stack;
    vector<bool> visited(size, false);

    for (int i = 0; i < size; i++)
        if (!visited[i])
            fillOrder(adj, i, visited, Stack);

    vector<int> transpose[size];
    for (int v = 0; v < size; v++) {
        for (int i : adj[v])
            transpose[i].push_back(v);
    }

    fill(visited.begin(), visited.end(), false);

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            DFSUtil(transpose, v, visited);
            cout << endl;
        }
    }
}

int main() {
    int size = 10;
    vector<int> adj[size];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 2, 7);
    addEdge(adj, 3, 8);
    addEdge(adj, 3, 9);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 7, 9);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    cout << "\nStrongly Connected Components:\n";
    findSCCs(adj, size);

    return 0;
}
