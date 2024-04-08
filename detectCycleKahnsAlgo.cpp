#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int v1, int v2){
    adj[v1].push_back(v2);
}

bool isCyclic(vector<int> adj[], int v){
    vector<int> indegree(v, 0);
    for(int i=0; i<v; i++){
        for(int a : adj[i]){
            indegree[a]++;
        }
    }

    int cnt=0;

    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int a : adj[u]){
            if(indegree[a]>0){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
    }
    cout << cnt;
    return cnt!=v;
}

int main(){
    int v=5;
    vector<int> adj[v];

    add_edge(adj, 0, 1);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 1);
    add_edge(adj, 4, 1);

    cout << "Is cyclic: " << isCyclic(adj, v);

    return 0;
}