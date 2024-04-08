#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

int capacity=10;
node* arr[20];

node* createNode(int key){
    node* temp=malloc(sizeof(node));
    temp->data=key;
    temp->next=NULL;
    return temp;
}

void insert(int key){
    node* temp=createNode(key);
    int index=key%capacity;

    if(arr[index]==NULL){
        arr[index]=temp;
    }
    else{
        node * t = arr[index];
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=temp;
    }
}

void printHash(node** arr){
    for(int i=0; i<capacity; i++){
        if(arr[i]==NULL){
            printf("[%d]\n", i);
        }
        else{
            printf("[%d] ", i);
            node* t=arr[i];
            while(t!=NULL){
                printf("%d -> ", t->data);
                t=t->next;
            }
            printf("\n");
        }
    }
}

void search(int key){
    int index=key%capacity;

    node* t=arr[index];

    while(t!=NULL){
        if(t->data==key){
            printf("Found!!\n");
            return;
        }
        else{
            t=t->next;
        }
    }

    printf("Not Found!!\n");
}

int main(){
    for(int i=0; i<capacity; i++){
        arr[i]=NULL;
    }

    insert(5);
    insert(15);
    insert(31);
    insert(56);
    insert(27);
    insert(11);
    insert(89);
    insert(7);
    insert(21);
    insert(42);
    insert(33);
    insert(19);
    insert(10);
    insert(25);
    insert(2);
    insert(12);
    insert(17);
    insert(28);
    insert(36);
    insert(44);
    insert(50);
    insert(62);
    insert(73);
    insert(85);
    insert(97);
    insert(14);
    insert(23);
    insert(39);
    insert(48);

    printHash(arr);


    search(1351356);
}