#include <iostream>
#include <vector>

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

    // DFS function to visit each node
    void DFS(int node, vector<vector<int> >& adj, vector<int>& ans, vector<bool>& visited) {
        visited[node] = 1;  // Mark the node as visited
        ans.push_back(node);  // Add node to the result
        // Traverse through all the neighbors
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                DFS(adj[node][i], adj, ans, visited);  // Recur for unvisited neighbors
            }
        }
    }

    // Function to perform DFS traversal and return the result
    vector<int> dfs() {
        vector<int> ans;  // To store the DFS traversal result
        vector<bool> visited(adj.size(), false);  // Keep track of visited nodes
        DFS(0, adj, ans, visited);  // Start DFS from node 0
        
        return ans;
    }

private:
    vector<vector<int> > adj;  // Adjacency list to store graph
};

int main() {
    // Create a Solution object that will automatically fill the adjacency list
    Solution sol;

    // Perform DFS traversal
    vector<int> result = sol.dfs();  // Perform DFS traversal starting from node 0

    // Output the DFS traversal result
    cout << "DFS Traversal Result: ";
    for (int i = 0 ; i < result.size() ; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
