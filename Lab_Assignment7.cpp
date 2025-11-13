#include <iostream>
#include <climits>
using namespace std;

#define V 6  // Number of delivery locations

// Function to find vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the Minimum Spanning Tree (MST)
void printMST(int parent[], int graph[V][V]) {
    int totalCost = 0;

    cout << "\nEdge \tWeight\n";
    cout << "------------------\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "\nMinimum Total Delivery Time: " << totalCost << " minutes\n";
}

// Function implementing Prim’s Algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Stores MST
    int key[V];     // Minimum edge weight to connect vertex
    bool mstSet[V]; // True if vertex is included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from first vertex
    key[0] = 0;
    parent[0] = -1;

    // Construct MST for V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the resulting MST
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 30, 5, 0, 0},
        {20, 30, 0, 15, 6, 0},
        {0, 5, 15, 0, 8, 9},
        {0, 0, 6, 8, 0, 12},
        {0, 0, 0, 9, 12, 0}
    };

    cout << "Minimum Delivery Path using Prim's Algorithm:\n";
    primMST(graph);

    return 0;
}
