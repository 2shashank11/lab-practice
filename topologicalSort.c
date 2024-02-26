#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct stack{
    int a[MAX];
    int top;
} stack;

void push(stack* s, int val){
    s->a[++(s->top)]=val;
}

int pop(stack* s){
    return s->a[s->top--];
}

int isEmpty(stack* s){
    return(s->top==-1);
}

void add_edge(int (*adj)[4], int v1, int v2){
    adj[v1][v2]=1;
}

void DFS(int (*adj)[4], int v, int start, int* visited, stack** s){
    visited[start]=1;
    for(int i=0; i<v; i++){
        if(adj[start][i]==1 && visited[i]==0){
            DFS(adj, v, i, visited, &*s);
        }
    }
    push(*s, start);
}

void topologicalSort(int (*adj)[4], int v){
    stack *s=malloc(sizeof(stack));
    s->top=-1;

    int visited[v];
    for(int i=0; i<v; i++){
        visited[i]=0;
    }

    for(int i=0; i<v; i++){
        if(visited[i]==0){
            DFS(adj, v, i, visited, &s);
        }
    }

    printf("Topological sort: ");
    while(!isEmpty(s)){
        printf("%d ", pop(s));
    }
}

int main(){

    int v=4;

    int adj[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<v; j++){
            adj[i][j]=0;
        }
    }

    add_edge(adj, 1, 0);
    add_edge(adj, 2, 0);
    add_edge(adj, 3, 0);

    topologicalSort(adj, v);
}