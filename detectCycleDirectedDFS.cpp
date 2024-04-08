#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
}

bool DFSRecur(vector<int> adj[], int s, vector<int> &visited, vector<int> &recSt){
    visited[s]=1;
    recSt[s]=1;
    for(int a : adj[s]){
        if(visited[a]==0 && DFSRecur(adj, a, visited, recSt)){
            return true;
        }
        else if(recSt[s]==1){
            return true;
        }
    }
    recSt[s]=0;
    return false;
}

bool isCyclic(vector<int> adj[], int v){
    vector<int> visited(v, 0);
    vector<int> recSt(v, 0);
    for(int i=0; i<v; i++){
        if(visited[i]==0){
            if(DFSRecur(adj, i, visited, recSt)==true){
                return true;
            }
        }
    }
    return false;
} 

int main(){
    int v=6;
    vector<int> adj[v];
    add_edge(adj, 0, 1);
    add_edge(adj, 2, 1);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 4);
    add_edge(adj, 4, 5);
    add_edge(adj, 5, 3);

    cout << "Is cyclic: " << isCyclic(adj, v);

    return 0;
}