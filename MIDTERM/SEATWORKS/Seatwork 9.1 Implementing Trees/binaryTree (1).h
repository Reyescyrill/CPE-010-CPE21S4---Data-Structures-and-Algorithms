#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
private:
    T key;
    // pointers for left and right child
    BinaryTree<T>* leftChild;
    BinaryTree<T>* rightChild;

public:
    // constructor:
    BinaryTree(T rootObj);

    void insertChildLeft(T newNode);
    void insertChildRight(T newNode);
    BinaryTree<T>* getLeftChild();
    BinaryTree<T>* getRightChild();
    T getRootVal();
    void setRootVal(T val);
};

// constructor:
template <typename T>
BinaryTree<T>::BinaryTree(T rootObj) {
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
}

// insert child:
template <typename T>
void BinaryTree<T>::insertChildLeft(T newNode) {
    if (leftChild == nullptr) {
        leftChild = new BinaryTree<T>(newNode);
    } else {
        BinaryTree<T>* tempNode = new BinaryTree<T>(newNode);
        // move the current left child below the new Node;
        tempNode->leftChild = leftChild;

        leftChild = tempNode;
    }
}

template <typename T>
void BinaryTree<T>::insertChildRight(T newNode) {
    if (rightChild == nullptr) {
        rightChild = new BinaryTree<T>(newNode);
    } else {
        BinaryTree<T>* tempNode = new BinaryTree<T>(newNode);
        tempNode->rightChild = rightChild;

        rightChild = tempNode;
    }
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
    return leftChild;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild() {
    return rightChild;
}

template <typename T>
T BinaryTree<T>::getRootVal() {
    return key;
}

template <typename T>
void BinaryTree<T>::setRootVal(T val) {
    key = val;
}

#endif