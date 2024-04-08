#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;

int max(int a, int b){
    return a>b?a:b;
}

int getHeight(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(getHeight(root->left), getHeight(root->right));
}

int getBalanceFactor(node* root){
    return getHeight(root->left)-getHeight(root->right);
}

node* createNode(int key){
    node* temp=malloc(sizeof(node));
    temp->data=key;
    temp->left=temp->right=NULL;
    temp->height=0;
    return temp;
}

node* rotateRight(node* root){
    node* T1=root->left;
    node* T2=T1->right;

    root->left=T2;
    T1->right=root;

    root->height=max(getHeight(root->right), getHeight(root->left));
    T1->height=max(getHeight(T1->right), getHeight(T1->left));

    return T1;

}

node* rotateLeft(node* root){
    node* T1=root->right;
    node* T2=T1->left;

    root->right=T2;
    T1->left=root;

    root->height=max(getHeight(root->right), getHeight(root->left));
    T1->height=max(getHeight(T1->right), getHeight(T1->left));

    return T1;
}

node* insertNode(node* root, int key){
    if(root==NULL){
        root=createNode(key);
    }

    if(key<root->data){
        root->left=insertNode(root->left, key);
    }
    else if(key>root->data){
        root->right=insertNode(root->right, key);
    }

    root->height=getHeight(root);

    int bf=getBalanceFactor(root);

    // LL
    if(bf>1 && key<root->left->data){
        return rotateRight(root);
    }
    // RR
    else if(bf<-1 && key>root->right->data){
        return rotateLeft(root);
    }
    // LR
    else if(bf>1 && key>root->left->data){
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }
    // RL
    else if(bf<-1 && key<root->right->data){
        root->right=(rotateRight(root->right));
        return rotateLeft(root);
    }
    
    return root;
}

void preorder(node* root){
    if(root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* root=NULL;

    root=insertNode(root, 1);
    root=insertNode(root, 2);
    root=insertNode(root, 4);
    root=insertNode(root, 5);
    root=insertNode(root, 6);
    root=insertNode(root, 3);
    preorder(root);
    return 0;
}