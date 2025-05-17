#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Create adjacency list
    vector<vector<int> > constructadj(int V, vector<vector<int> > &edges) {
        vector<vector<int> > adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        return adj;
    }

    // DFS function
    void DFS(vector<bool> &visited, int node, vector<vector<int> > &adj, stack<int> &s) {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];
            if (!visited[next]) {
                DFS(visited, next, adj, s);
            }
        }
        s.push(node);
    }

    // Topological sort
    vector<int> topoSort(int V, vector<vector<int> > &edges) {
        stack<int> s;
        vector<bool> visited(V, false);
        vector<vector<int> > adj = constructadj(V, edges);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(visited, i, adj, s);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int V = 6;
    vector<vector<int> > edges;

    // Manual push_back for each edge (C++98 compatible)
    edges.push_back(vector<int>(2)); edges[0][0] = 5; edges[0][1] = 2;
    edges.push_back(vector<int>(2)); edges[1][0] = 5; edges[1][1] = 0;
    edges.push_back(vector<int>(2)); edges[2][0] = 4; edges[2][1] = 0;
    edges.push_back(vector<int>(2)); edges[3][0] = 4; edges[3][1] = 1;
    edges.push_back(vector<int>(2)); edges[4][0] = 2; edges[4][1] = 3;
    edges.push_back(vector<int>(2)); edges[5][0] = 3; edges[5][1] = 1;

    vector<int> result = sol.topoSort(V, edges);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
