/********************************************************************************
* WARNING: Please do not remove or modify this comment block.
 *
 * Student Information:
 * Name: Mohamed Elshemy
 * Student ID: 900193930
 * Section Number: 1
 *
 * Instructions:
 * - Fill out your name, student ID, and section number above.
 * - This information is mandatory for the submission of your assignment.
 * - Do not modify this file beyond the specified tasks and guidelines.
 *
 ********************************************************************************/

#include "dijkstra.h"
#include "floyd.h"
#include "graph.h"
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(int src) {
    vector<int> dist(n, 1e9);

    // Initialize priority queue (min-heap: stores {distance, vertex})
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Set dist[src] = 0 and push into pq
    dist[src] = 0;
    pq.push({0, src});

    // Dijkstra main loop
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a shorter path to u already, skip it
        if (d > dist[u]) continue;

        // Traverse all adjacent vertices of u
        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

vector<vector<int>> repeatedDijkstra() {
    vector<vector<int>> all(n, vector<int>(n));

    // Run dijkstra(i) for all nodes to build the All-Pairs Shortest Path matrix
    for (int i = 0; i < n; i++) {
        all[i] = dijkstra(i);
    }

    return all;
}

vector<vector<int>> floydWarshall() {
    // Start with the initial adjacency matrix
    vector<vector<int>> dist = adjMatrix;

    // The triple loop: k is the intermediate node, i is the source, j is the destination
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If the path through k is shorter than the current shortest path from i to j, update it
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}
