#include <stdio.h>
#include <stdlib.h>

#define OFFSET 0x41

typedef struct Node {
    int left;
    int right;
} Node;

void preorder(Node* tree, int node);
void inorder(Node* tree, int node);
void postorder(Node* tree, int node);

int main(){
    Node tree[26];
    for (int i=0; i<26; i++){
        tree[i].left = -1;
        tree[i].right = -1;
    }
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        char p,l,r;
        scanf(" %c %c %c",&p, &l, &r);
        if (l != '.')
            tree[p-OFFSET].left = l-OFFSET;
        if (r != '.')
            tree[p-OFFSET].right = r-OFFSET;
    }


    preorder(tree,0);
    printf("\n");
    inorder(tree,0);
    printf("\n");
    postorder(tree,0);
}

void preorder(Node* tree, int node){
    if (node == -1)
        return;
    printf("%c",node+OFFSET);
    preorder(tree,tree[node].left);
    preorder(tree,tree[node].right);
}

void inorder(Node* tree, int node){
    if (node == -1)
        return;
    inorder(tree,tree[node].left);
    printf("%c",node+OFFSET);
    inorder(tree,tree[node].right);
}

void postorder(Node* tree, int node){
    if (node == -1)
        return;
    postorder(tree,tree[node].left);
    postorder(tree,tree[node].right);
    printf("%c",node+OFFSET);
}
