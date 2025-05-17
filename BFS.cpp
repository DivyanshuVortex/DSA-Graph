#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Constructor to initialize the adjacency list
    Solution() {
        // Initialize the adjacency list with 10 vertices
        adj.resize(10);

        // Fill the adjacency list with connections using push_back
        adj[0].push_back(1);
        adj[0].push_back(2);
        adj[0].push_back(3);
        adj[0].push_back(4);

        adj[1].push_back(0);
        adj[1].push_back(5);
        adj[1].push_back(6);

        adj[2].push_back(0);
        adj[2].push_back(5);
        adj[2].push_back(7);

        adj[3].push_back(0);
        adj[3].push_back(6);
        adj[3].push_back(8);

        adj[4].push_back(0);
        adj[4].push_back(7);
        adj[4].push_back(9);

        adj[5].push_back(1);
        adj[5].push_back(2);
        adj[5].push_back(8);

        adj[6].push_back(1);
        adj[6].push_back(3);
        adj[6].push_back(9);

        adj[7].push_back(2);
        adj[7].push_back(4);
        adj[7].push_back(9);

        adj[8].push_back(3);
        adj[8].push_back(5);

        adj[9].push_back(4);
        adj[9].push_back(6);
        adj[9].push_back(7);
    }

    // BFS function to traverse the graph
    vector<int> bfs() {
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                if (!visited[adj[node][i]]) {
                    q.push(adj[node][i]);
                    visited[adj[node][i]] = true;
                }
            }
        }

        return ans;
    }

private:
    vector<vector<int> > adj;
};

int main() {
    Solution sol;

    // Perform BFS traversal
    vector<int> result = sol.bfs();

    // Output the BFS traversal result
    cout << "BFS Traversal Result: ";
   for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
