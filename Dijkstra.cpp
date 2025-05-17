#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's Algorithm implementation
typedef pair<int, int> p;  // (distance, node)

vector<int> dijkstra(int V, vector<vector<int> >& edges, int S) {
    vector<vector<p> > adj(V);

    // Building adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int sour = edges[i][0];
        int desti = edges[i][1];
        int wei = edges[i][2];
        adj[sour].push_back(p(desti, wei));  // Adding edge to adjacency list
        adj[desti].push_back(p(sour, wei));  // Undirected Graph
    }

    vector<int> dist(V, INT_MAX);  // Distance vector initialized to INF
    dist[S] = 0;  // Starting node has distance 0

    // Priority queue to fetch the minimum distance node
    priority_queue<p, vector<p>, greater<p> > pq;
    pq.push(p(0, S));  // Dist :: Node (start node has distance 0)

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        // Explore neighbors of the current node
        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i].first;
            int weight = adj[node][i].second;

            // Relax the edge if a shorter path is found
            if (dist[neigh] > dist[node] + weight) {
                dist[neigh] = dist[node] + weight;
                pq.push(p(dist[neigh], neigh));
            }
        }
    }

    return dist;
}

// Function to print the result of distances
void printResult(const vector<int>& dist) {
    for (size_t i = 0; i < dist.size(); ++i) {
        if (dist[i] == INT_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test Case 1
    int V1 = 5;
    vector<vector<int> > edges1;
    edges1.push_back(vector<int>(3, 0)); edges1[0][0] = 0; edges1[0][1] = 1; edges1[0][2] = 9;
    edges1.push_back(vector<int>(3, 0)); edges1[1][0] = 0; edges1[1][1] = 2; edges1[1][2] = 6;
    edges1.push_back(vector<int>(3, 0)); edges1[2][0] = 1; edges1[2][1] = 2; edges1[2][2] = 3;
    edges1.push_back(vector<int>(3, 0)); edges1[3][0] = 1; edges1[3][1] = 3; edges1[3][2] = 1;
    edges1.push_back(vector<int>(3, 0)); edges1[4][0] = 2; edges1[4][1] = 3; edges1[4][2] = 2;
    edges1.push_back(vector<int>(3, 0)); edges1[5][0] = 3; edges1[5][1] = 4; edges1[5][2] = 4;
    cout << "Test Case 1: Expected: 0 9 6 8 12\n";
    printResult(dijkstra(V1, edges1, 0));

    // Test Case 2
    int V2 = 3;
    vector<vector<int> > edges2;
    edges2.push_back(vector<int>(3, 0)); edges2[0][0] = 0; edges2[0][1] = 1; edges2[0][2] = 5;
    edges2.push_back(vector<int>(3, 0)); edges2[1][0] = 1; edges2[1][1] = 2; edges2[1][2] = 2;
    edges2.push_back(vector<int>(3, 0)); edges2[2][0] = 0; edges2[2][1] = 2; edges2[2][2] = 10;
    cout << "Test Case 2: Expected: 0 5 7\n";
    printResult(dijkstra(V2, edges2, 0));

    // Test Case 3
    int V3 = 4;
    vector<vector<int> > edges3;
    edges3.push_back(vector<int>(3, 0)); edges3[0][0] = 0; edges3[0][1] = 1; edges3[0][2] = 1;
    edges3.push_back(vector<int>(3, 0)); edges3[1][0] = 1; edges3[1][1] = 2; edges3[1][2] = 2;
    edges3.push_back(vector<int>(3, 0)); edges3[2][0] = 2; edges3[2][1] = 3; edges3[2][2] = 3;
    cout << "Test Case 3: Expected: 0 1 3 6\n";
    printResult(dijkstra(V3, edges3, 0));

    // Test Case 4 - Simple cycle with 3 nodes
    int V4 = 3;
    vector<vector<int> > edges4;
    edges4.push_back(vector<int>(3, 0)); edges4[0][0] = 0; edges4[0][1] = 1; edges4[0][2] = 2;
    edges4.push_back(vector<int>(3, 0)); edges4[1][0] = 1; edges4[1][1] = 2; edges4[1][2] = 3;
    edges4.push_back(vector<int>(3, 0)); edges4[2][0] = 2; edges4[2][1] = 0; edges4[2][2] = 1;
    cout << "Test Case 4: Expected: 0 2 3\n";
    printResult(dijkstra(V4, edges4, 0));

    // Test Case 5 - No edges (disconnected graph)
    int V5 = 4;
    vector<vector<int> > edges5;
    cout << "Test Case 5: Expected: 0 INF INF INF\n";
    printResult(dijkstra(V5, edges5, 0));

    // Test Case 6 - Fully connected graph
    int V6 = 4;
    vector<vector<int> > edges6;
    edges6.push_back(vector<int>(3, 0)); edges6[0][0] = 0; edges6[0][1] = 1; edges6[0][2] = 10;
    edges6.push_back(vector<int>(3, 0)); edges6[1][0] = 0; edges6[1][1] = 2; edges6[1][2] = 5;
    edges6.push_back(vector<int>(3, 0)); edges6[2][0] = 1; edges6[2][1] = 2; edges6[2][2] = 2;
    edges6.push_back(vector<int>(3, 0)); edges6[3][0] = 1; edges6[3][1] = 3; edges6[3][2] = 1;
    edges6.push_back(vector<int>(3, 0)); edges6[4][0] = 2; edges6[4][1] = 3; edges6[4][2] = 3;
    cout << "Test Case 6: Expected: 0 7 5 8\n";
    printResult(dijkstra(V6, edges6, 0));

    // Test Case 7 - Graph with multiple paths
    int V7 = 4;
    vector<vector<int> > edges7;
    edges7.push_back(vector<int>(3, 0)); edges7[0][0] = 0; edges7[0][1] = 1; edges7[0][2] = 1;
    edges7.push_back(vector<int>(3, 0)); edges7[1][0] = 1; edges7[1][1] = 2; edges7[1][2] = 5;
    edges7.push_back(vector<int>(3, 0)); edges7[2][0] = 0; edges7[2][1] = 2; edges7[2][2] = 3;
    edges7.push_back(vector<int>(3, 0)); edges7[3][0] = 2; edges7[3][1] = 3; edges7[3][2] = 1;
    cout << "Test Case 7: Expected: 0 1 3 4\n";
    printResult(dijkstra(V7, edges7, 0));

    return 0;
}
