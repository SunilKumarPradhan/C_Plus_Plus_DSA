#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void tarjanDFS(int u, vector<int>& disc, vector<int>& low, stack<int>& stk, vector<bool>& inStack, vector<int> adj[], vector<vector<int>>& SCCs) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    stk.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, disc, low, stk, inStack, adj, SCCs);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        vector<int> component;
        int w;
        do {
            w = stk.top();
            stk.pop();
            inStack[w] = false;
            component.push_back(w);
        } while (w != u);
        SCCs.push_back(component);
    }
}

vector<vector<int>> tarjan(vector<int> adj[], int V) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> stk;
    vector<vector<int>> SCCs;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            tarjanDFS(i, disc, low, stk, inStack, adj, SCCs);
        }
    }

    return SCCs;
}

int main() {
    int size = 10;
    vector<int> adj[size];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    addEdge(adj, 6, 5);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 6);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    vector<vector<int>> SCCs = tarjan(adj, size);

    cout << "\nStrongly Connected Components:" << endl;
    for (const auto& component : SCCs) {
        for (int v : component) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}