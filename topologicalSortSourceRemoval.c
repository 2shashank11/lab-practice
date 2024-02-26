#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct queue {
    int a[MAX];
    int front, rear;
} queue;

void push(queue *q, int val) {
    if(q->front == -1) {
        q->front++;
    }
    q->a[++(q->rear)] = val;
}

int delete(queue* q) {
    int dequeued = q->a[q->front];
    q->front++;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return dequeued;
}

int isEmpty(queue *q) {
    return (q->front == -1);
}

void add_edge(int (*adj)[6], int v1, int v2) {
    adj[v1][v2] = 1;
}

void topologicalSort(int v, int (*adj)[6]) {
    int indegree[v];
    for(int i = 0; i < v; i++) {
        indegree[i] = 0;
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    queue *q = malloc(sizeof(queue));
    q->front = q->rear = -1;

    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            push(q, i);
        }
    }

    while(!isEmpty(q)) {
        int u = delete(q);
        printf("%d ", u);

        for(int i = 0; i < v; i++) {
            if(adj[u][i] == 1 && indegree[i] > 0) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    push(q, i);
                }
            }
        }
    }

    free(q);
}

int main() {
    int v = 6;

    int adj[v][v];
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    add_edge(adj, 4, 0);
    add_edge(adj, 5, 0);
    add_edge(adj, 5, 2);
    add_edge(adj, 2, 3);
    add_edge(adj, 1, 3);
    add_edge(adj, 4, 1);

    topologicalSort(v, adj);
    return 0;
}
