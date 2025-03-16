#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* binarySearch(Node* node, int data) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < node->data) {
        node->left = binarySearch(node->left, data);
    } else if (data > node->data) {
        node->right = binarySearch(node->right, data);
    }
    return node;
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}

int main() {
    int num;
    Node* root = NULL;
    while (scanf("%d",&num) != EOF){
        root = binarySearch(root,num);
    }
    postorder(root);
}