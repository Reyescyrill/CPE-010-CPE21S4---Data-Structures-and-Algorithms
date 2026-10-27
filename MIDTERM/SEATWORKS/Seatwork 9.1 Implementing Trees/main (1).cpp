#include <iostream>
#include "binaryTree.h"

int main() {

    BinaryTree<char>* root = new BinaryTree<char>('A');
    root->insertChildLeft('B');
    root->insertChildRight('C');

    root->getLeftChild()->insertChildLeft('D');
    root->getLeftChild()->insertChildRight('E');
    root->getRightChild()->insertChildRight('D');

    // Display Root and Immediate Children
    std::cout << "The root: " << root->getRootVal() << std::endl;
    std::cout << "The left child of root a is: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout << "The right child of root a is: " << root->getRightChild()->getRootVal() << std::endl;

    // Display Sub-children (Children of 'B')
    std::cout << "The left child of B is: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "The right child of B is: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;

    // Update 'C' to 'V' and print result
    root->getRightChild()->setRootVal('V');
    std::cout << "Updated right child of root a is: " << root->getRightChild()->getRootVal() << std::endl;
    std::cout << "The right child of V is: " << root->getRightChild()->getRightChild()->getRootVal() << std::endl;

    return 0;
}