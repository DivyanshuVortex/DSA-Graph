#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kahnAlgo(int V,vector<vector<int> >& adj){
    vector<int> Indeg(V,0);
    vector<int> ans;
    // Filling the Indeg
    for(int i =0;i<V;i++)
    for(int j = 0; j < adj[i].size();j++)
    Indeg[adj[i][j]]++;

    //Basic BFS
    queue<int> q;
    for(int i = 0; i < V;i++){
        if(Indeg[i] == 0) q.push(i);
    }
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);// change the indeg after ppushing into answer
            for(int j = 0; j < adj[node].size();j++){
                Indeg[adj[node][j]]--;

                if(Indeg[adj[node][j]] == 0) q.push(adj[node][j]);
            }
        }
//Print the answer 
for(int d = 0; d < ans.size();d++) cout<<ans[d]<<" ";
cout<<endl;

};

int main() {
    int vertices = 6;
    vector<vector<int> > adj(vertices);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    kahnAlgo(vertices, adj);

    return 0;
}
