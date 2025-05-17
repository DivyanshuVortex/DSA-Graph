#include<iostream>
#include<vector>
using namespace std;

int main(){
int vex , edge ;
cin>>vex>>edge;
 vector<vector<pair<int, int> > > AdjList(vex);

int u,v,weight;
for(int i = 0; i < edge ; i++){
    cin>>u>>v>>weight;
    AdjList[u].push_back(make_pair(v,weight));
}



// Print 
for(int i =0 ; i < vex ; i++){
    cout<<i<<" -> ";
    for(int j = 0; j < AdjList[i].size() ;j++){
         cout << "(" << AdjList[i][j].first << ", " << AdjList[i][j].second << ") ";
    }
    cout<<endl;
}





return 0;
}