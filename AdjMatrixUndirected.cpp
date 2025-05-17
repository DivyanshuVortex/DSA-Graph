#include<iostream>
#include<vector>
using namespace std;

int main(){
int vex , edge ;
cin>>vex>>edge;
vector<vector<bool> > AdjMat(vex, vector<bool>(vex,0));

int u,v;
for(int i = 0; i < edge ; i++){
    cin>>u>>v;
AdjMat[u][v] = 1;
AdjMat[v][u] = 1;
}



// Print 
for(int i =0 ; i < vex ; i++){
    for(int j = 0; j < vex ;j++){
        cout<<AdjMat[i][j]<<" ";
    }
    cout<<endl;
}





return 0;
}