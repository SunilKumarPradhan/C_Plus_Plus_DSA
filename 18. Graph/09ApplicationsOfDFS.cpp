#include <bits/stdc++.h>
using namespace std;

// // Please see the notes given below

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

/*
Applications of Depth First Search (DFS):

1. Path Finding:
   - DFS can be used to find a path between two nodes in a graph. It explores each branch of the graph as deeply as possible before backtracking, making it suitable for maze solving and finding paths in games or puzzles.

2. Cycle Detection:
   - DFS is commonly used to detect cycles in a graph. By tracking the visited nodes and the recursion stack, DFS can determine if a graph contains any cycles, which is essential in detecting deadlocks in operating systems and preventing infinite loops in code.

3. Topological Sorting:
   - In Directed Acyclic Graphs (DAGs), DFS is used to perform topological sorting. This ordering of vertices is crucial in scheduling tasks, resolving symbol dependencies in compilers, and ordering cells in spreadsheets.

4. Strongly Connected Components (SCC):
   - DFS is used in algorithms like Kosaraju’s and Tarjan’s to find all the strongly connected components in a directed graph. This is important in understanding the structure of networks, optimizing component reuse in software, and analyzing social networks.

5. Connected Components:
   - In an undirected graph, DFS can identify all the connected components. This application is useful in image processing (finding all connected pixels), social network analysis (finding communities), and clustering problems.

6. Solving Puzzles and Games:
   - DFS can be applied to solve puzzles like Sudoku, N-Queens problem, and to explore all possible moves in games like chess or tic-tac-toe. It helps in finding solutions by exploring all potential states.

7. Network Analysis:
   - DFS is used to traverse networks and understand their structure. It helps in network flow analysis, network reliability, and network topology.

8. Artificial Intelligence:
   - In AI, DFS is used in searching algorithms like the minimax algorithm in game theory, and in exploring state spaces in problem-solving and planning.

9. Web Crawlers:
   - Web crawlers use DFS to traverse web pages. By visiting each page and following links recursively, crawlers can index the web efficiently.

10. File System Navigation:
    - DFS is used in file system navigation to list all files and directories. It explores each directory and its subdirectories deeply, making it suitable for directory tree traversal and disk usage analysis.

These applications demonstrate the versatility and importance of DFS in various fields ranging from computer science to network analysis and artificial intelligence.
*/


    return 0;
}
