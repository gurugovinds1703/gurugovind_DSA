#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

/
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct TreeNode* insert(struct TreeNode* root, int key) {
    // If tree is empty, create new node
    if (root == NULL) {
        return createNode(key);
    }

    
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // If key is greater, go right
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}


void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct TreeNode* root = NULL;

    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-order Traversal: ");
    inOrderTraversal(root);

    printf("\nPre-order Traversal: ");
    preOrderTraversal(root);

    printf("\nPost-order Traversal: ");
    postOrderTraversal(root);

    return 0;
}