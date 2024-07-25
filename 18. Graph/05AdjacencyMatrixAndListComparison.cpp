#include <iostream>
using namespace std;

int main() {
    cout << "Graph Representations and Comparisons in C++\n\n";

    cout << "Graphs:\n";
    cout << "- A graph is a data structure consisting of a set of vertices (nodes) and edges (connections between nodes).\n\n";

    cout << "1. Directed Graph (Digraph):\n";
    cout << "- In a directed graph, edges have a direction, going from one vertex to another.\n";
    cout << "- Represented as G = (V, E) where V is a set of vertices and E is a set of directed edges.\n";
    cout << "- Example: If there's a directed edge from vertex A to vertex B, it's represented as (A -> B).\n\n";

    cout << "Formulas:\n";
    cout << "- In-degree of a vertex v: Number of edges directed into v.\n";
    cout << "- Out-degree of a vertex v: Number of edges directed out of v.\n";
    cout << "- Sum of in-degrees = Sum of out-degrees = Number of edges (|E|).\n\n";

    cout << "Properties:\n";
    cout << "- Asymmetric: If (u -> v) exists, (v -> u) may or may not exist.\n";
    cout << "- Can contain cycles (a path where the starting and ending vertex is the same).\n\n";

    cout << "2. Undirected Graph:\n";
    cout << "- In an undirected graph, edges do not have a direction.\n";
    cout << "- Represented as G = (V, E) where V is a set of vertices and E is a set of undirected edges.\n";
    cout << "- Example: If there's an undirected edge between vertex A and vertex B, it's represented as (A - B).\n\n";

    cout << "Formulas:\n";
    cout << "- Degree of a vertex v: Number of edges connected to v.\n";
    cout << "- Sum of degrees of all vertices = 2 * Number of edges (2|E|).\n\n";

    cout << "Properties:\n";
    cout << "- Symmetric: If (u - v) exists, (v - u) also exists.\n";
    cout << "- Can contain cycles and multiple components.\n\n";

    cout << "Differences between Trees and Graphs:\n\n";

    cout << "1. Trees:\n";
    cout << "- A tree is a special type of graph with no cycles and is connected.\n";
    cout << "- A tree with n vertices has exactly (n-1) edges.\n";
    cout << "- There is exactly one path between any two vertices.\n";
    cout << "- Example: Binary Tree, AVL Tree.\n\n";

    cout << "Properties:\n";
    cout << "- Connected and acyclic.\n";
    cout << "- Rooted tree: Has a designated root node and directed edges.\n\n";

    cout << "2. Graphs:\n";
    cout << "- Can be cyclic or acyclic, connected or disconnected.\n";
    cout << "- No fixed number of edges; can have any number of edges.\n";
    cout << "- Multiple paths can exist between two vertices.\n\n";

    cout << "Formulas and Properties:\n";
    cout << "- For a connected graph, there exists at least one path between any two vertices.\n";
    cout << "- In a tree, the number of edges is always (number of vertices - 1).\n";
    cout << "- A tree is a minimally connected graph.\n\n";

    cout << "Difference Summary:\n";
    cout << "- Trees are a subset of graphs.\n";
    cout << "- Trees are connected and acyclic, graphs can have cycles and be disconnected.\n";
    cout << "- In trees, the number of edges is one less than the number of vertices, whereas in graphs, there is no such constraint.\n\n";

    cout << "Adjacency Matrix vs Adjacency List:\n\n";

    cout << "1. Adjacency Matrix:\n";
    cout << "- An adjacency matrix is a 2D array of size VxV where V is the number of vertices in the graph.\n";
    cout << "- The cell at row i and column j represents the presence (and sometimes weight) of an edge between vertices i and j.\n\n";

    cout << "Formulas:\n";
    cout << "- Space Complexity: O(V^2), where V is the number of vertices.\n";
    cout << "- Time Complexity to check if an edge exists between two vertices: O(1).\n";
    cout << "- Time Complexity to iterate through all edges: O(V^2).\n\n";

    cout << "Properties:\n";
    cout << "- Suitable for dense graphs where the number of edges is close to the number of vertices squared (|E| ≈ |V|^2).\n";
    cout << "- Simple to implement.\n";
    cout << "- Easy to check the presence/absence of a specific edge.\n\n";

    cout << "Example:\n";
    cout << "    Adjacency Matrix for a graph with 4 vertices:\n";
    cout << "        0  1  2  3\n";
    cout << "    0  [0, 1, 0, 0]\n";
    cout << "    1  [1, 0, 1, 1]\n";
    cout << "    2  [0, 1, 0, 1]\n";
    cout << "    3  [0, 1, 1, 0]\n\n";

    cout << "2. Adjacency List:\n";
    cout << "- An adjacency list is an array of lists. The array size is V where V is the number of vertices.\n";
    cout << "- Each index i in the array represents a vertex, and the list at index i contains all the vertices adjacent to vertex i.\n\n";

    cout << "Formulas:\n";
    cout << "- Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges.\n";
    cout << "- Time Complexity to check if an edge exists between two vertices: O(V) in the worst case.\n";
    cout << "- Time Complexity to iterate through all edges: O(V + E).\n\n";

    cout << "Properties:\n";
    cout << "- Suitable for sparse graphs where the number of edges is much less than the number of vertices squared (|E| << |V|^2).\n";
    cout << "- More efficient in terms of space for large, sparse graphs.\n";
    cout << "- More complex to implement compared to adjacency matrix.\n\n";

    cout << "Example:\n";
    cout << "    Adjacency List for a graph with 4 vertices:\n";
    cout << "    0: [1]\n";
    cout << "    1: [0, 2, 3]\n";
    cout << "    2: [1, 3]\n";
    cout << "    3: [1, 2]\n\n";

    cout << "Difference Summary:\n";
    cout << "- **Space Complexity:** Adjacency Matrix uses O(V^2) space, while Adjacency List uses O(V + E) space.\n";
    cout << "- **Edge Check:** Adjacency Matrix allows O(1) time complexity for checking the presence of an edge, whereas Adjacency List may take O(V) time.\n";
    cout << "- **Memory Usage:** Adjacency List is more memory efficient for sparse graphs, whereas Adjacency Matrix can be inefficient for such graphs.\n";
    cout << "- **Implementation:** Adjacency Matrix is simpler to implement but can be less efficient for graphs with many vertices but few edges.\n";
    cout << "- **Use Cases:** Use Adjacency Matrix for dense graphs and Adjacency List for sparse graphs.\n";

    return 0;
}
