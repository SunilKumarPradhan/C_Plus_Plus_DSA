#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

    void topologicalSortDFSUtil(int v, vector<int> adj[], vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortDFSUtil(i, adj, visited, Stack);
    }

    Stack.push(v);
}

vector<int> topologicalSortDFS(int size, vector<int> adj[]) {
    stack<int> Stack;
    vector<bool> visited(size, false);

    for (int i = 0; i < size; i++) {
        if (!visited[i])
            topologicalSortDFSUtil(i, adj, visited, Stack);
    }

    vector<int> top_order;
    while (!Stack.empty()) {
        top_order.push_back(Stack.top());
        Stack.pop();
    }

    return top_order;
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

    cout << "Adjacency List Representation:"<<endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    vector<int> result = topologicalSortDFS(size, adj);

    for (int v : result)
        cout << v << " ";
    cout << endl;

    return 0;
}
