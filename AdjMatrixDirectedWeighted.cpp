#include<iostream>
#include<vector>
using namespace std;

int main(){
int vex , edge ;
cin>>vex>>edge;
vector<vector<int> > AdjMat(vex, vector<int>(vex,0));

int u,v,weight;
for(int i = 0; i < edge ; i++){
    cin>>u>>v>>weight;
AdjMat[u][v] = weight;
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