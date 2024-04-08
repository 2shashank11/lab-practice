#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

bool DFSRecur(vector<int> adj[], int s, vector<int> &visited, int parent){
    visited[s]=1;
    for(int a : adj[s]){
        if(visited[a]==0){
            if(DFSRecur(adj, a, visited, s)==true){
                return true;
            }
        }
        else if( a!= parent){
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[], int s, int v){
    vector<int> visited(v, 0);
    for(int i=0; i<v; i++){
        if(visited[i]==0){
            if(DFSRecur(adj, i, visited, -1)==true){
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
    add_edge(adj, 1, 2);
    add_edge(adj, 1, 3);
    add_edge(adj, 2, 3);
    add_edge(adj, 2, 4);
    add_edge(adj, 4, 5);

    cout << "is cyclic: " << DFS(adj, 0, v);
    return 0;
}