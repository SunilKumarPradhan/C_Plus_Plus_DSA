#include <bits/stdc++.h>
using namespace std;

// Please see the notes given below

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


/*
Applications of BFS:

1. Shortest Path in Unweighted Graph:
   - BFS is used to find the shortest path from a source node to a target node in an unweighted graph. It ensures that the path found is the one with the fewest edges.

2. Web Crawlers:
   - BFS is used by web crawlers to traverse the web. Starting from a seed URL, it visits the neighbors (linked pages) level by level.

3. Social Networking Sites:
   - BFS can be used to find the shortest connection path between two users in a social network or to find all friends within a certain number of hops.

4. Peer-to-Peer Networks:
   - In P2P networks, BFS can be used to find all nodes that are reachable from a given node or to broadcast information across the network.

5. Network Broadcasting:
   - BFS can be used to broadcast information (e.g., updates, messages) to all nodes in a network efficiently.

6. Garbage Collection:
   - BFS is used in the mark-and-sweep garbage collection algorithm to mark reachable objects in memory.

7. Finding Connected Components:
   - In an undirected graph, BFS can be used to find all connected components by starting a BFS from every unvisited node.

8. Cycle Detection:
   - BFS can help detect cycles in an undirected graph by keeping track of the parent nodes.

9. Bipartite Graph Checking:
   - BFS can be used to check if a graph is bipartite by attempting to color the graph using two colors and checking for conflicts.

10. Pathfinding Algorithms:
    - BFS is a fundamental part of many pathfinding algorithms, including those used in artificial intelligence for games and simulations.

11. Level Order Traversal in Trees:
    - BFS is used for level order traversal of trees, visiting nodes level by level from the root down.

12. Flood Fill Algorithm:
    - BFS is used in the flood fill algorithm, which is used in graphics programs to determine the area connected to a given node in a multi-dimensional array.

These applications highlight the versatility and importance of BFS in various fields, including computer science, networking, artificial intelligence, and more.
*/
