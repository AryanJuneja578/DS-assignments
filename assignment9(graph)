#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;             
    bool directed;              
    vector<vector<int>> adjMat;
    vector<vector<int>> adjList;
public:
    Graph(int vertices, bool isDirected = false) {
        V = vertices;
        directed = isDirected;
        adjMat.assign(V, vector<int>(V, 0));
        adjList.assign(V, vector<int>());
    }

    void addEdge(int u, int v) {
        if (u<0 || v<0 || u>=V || v>=V) {
            cout << "Invalid vertex number!\n";
            return;
        }

        adjMat[u][v] = 1;
        adjList[u].push_back(v);

        if (!directed) {
            adjMat[v][u] = 1;
            adjList[v].push_back(u);
        }
    }

    void degree(int v) {
        if (v < 0 || v >= V) { 
            cout << "Invalid vertex!\n"; 
            return; 
        }

        if (!directed) {
            cout << "Degree of vertex " << v << " = " << adjList[v].size() << endl;
            return;
        }

        int outdeg = adjList[v].size();
        int indeg = 0;

        for (int i = 0; i < V; i++)
            if (adjMat[i][v] == 1)
                indeg++;

        cout << "Out-degree of " << v << " = " << outdeg << endl;
        cout << "In-degree of " << v << " = " << indeg << endl;
    }

    void adjacentVertices(int v) {
        if (v < 0 || v >= V) {
            cout << "Invalid vertex!\n";
            return;
        }
        cout << "Adjacent vertices of " << v << ": ";
        for (int x : adjList[v])
            cout << x << " ";
        cout << endl;
    }

    void countEdges() {
        int edges = 0;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (adjMat[i][j] == 1)
                    edges++;

        if (!directed) edges /= 2; 
        cout << "Total number of edges = " << edges << endl;
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMat[i][j] << " ";
            cout << endl;
        }
    }

    void displayList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int x : adjList[i])
                cout << x << " ";
            cout << endl;
        }
    }
};


int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V, false);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter each edge as: u v\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\n";
    g.displayMatrix();
    cout << "\n";
    g.displayList();

    cout << "\n--- Operations ---\n";
    int vertex;
    cout << "Enter vertex to find degree: ";
    cin >> vertex;
    g.degree(vertex);

    cout << "\nEnter vertex to list adjacent vertices: ";
    cin >> vertex;
    g.adjacentVertices(vertex);

    cout << endl;
    g.countEdges();

    return 0;
}
