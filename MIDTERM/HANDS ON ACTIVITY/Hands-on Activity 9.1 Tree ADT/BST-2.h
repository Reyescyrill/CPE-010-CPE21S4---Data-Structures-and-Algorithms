#pragma once
#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

inline Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

inline void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    std::cout << root->val << " ";
    inOrder(root->right);
}

inline void preOrder(Node* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

inline void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->val << " ";
}