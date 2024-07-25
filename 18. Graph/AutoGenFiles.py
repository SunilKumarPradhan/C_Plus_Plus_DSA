import os

cpp_template = """#include <bits/stdc++.h>
using namespace std;



void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
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



    
    return 0;
}
"""

# Read the filenames from the text file
with open('QuestionList.txt', 'r') as file:
    filenames = file.readlines()

# Create .cpp files with the template
for name in filenames:
    filename = name.strip() + '.cpp'  # Remove any leading/trailing whitespace and add .cpp extension
    with open(filename, 'w') as cpp_file:
        cpp_file.write(cpp_template)
    
    print(f"Created file: {filename}")
