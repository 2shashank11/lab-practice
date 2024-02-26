#include<stdio.h>
#include<stdbool.h>

void add_edge(int v, int (*adj)[v], int v1, int v2){
    adj[v1][v2]=1;
    adj[v2][v1]=1;
}

bool DFS(int v, int (*adj)[v], int s, int *visited, int parent){
    visited[s]=1;
    for(int i=0; i<v; i++){
        if(adj[s][i]==1){
            if(visited[i]==0){
                if(DFS(v, adj, i, visited, s)==true){
                    return true;
                }
            }
            else if(parent!=i){
                return true;
            }
        }
        
    }
    return false;
}

bool isCyclic(int v, int (*adj)[v]){
    int visited[v];
    for(int i=0; i<v; i++){
        visited[i]=0;
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(adj[i][j]==1 && visited[j]==0){
                if(DFS(v, adj, j, visited, -1)==true){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int v=6;
    int adj[v][v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    add_edge(v, adj, 0, 1);
    add_edge(v, adj, 1, 2);
    add_edge(v, adj, 1, 3);
    add_edge(v, adj, 2, 3);
    add_edge(v, adj, 2, 4);
    add_edge(v, adj, 4, 5);

    // add_edge(v, adj, 0, 1);

    printf("Cyclic: %d", isCyclic(v, adj));

    return 0;
}