#include<iostream>
#include<vector>
using namespace std;

int main(){
int vex , edge ;
cin>>vex>>edge;
 vector<vector<int> > AdjList(vex);

int u,v;
for(int i = 0; i < edge ; i++){
    cin>>u>>v;
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
}



// Print 
for(int i =0 ; i < vex ; i++){
    cout<<i<<" -> ";
    for(int j = 0; j < AdjList[i].size() ;j++){
        cout<<AdjList[i][j]<<" ";
    }
    cout<<endl;
}





return 0;
}