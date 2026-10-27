#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    Node* tree = nullptr;
    int items[] = {2, 3, 9, 18, 0, 1, 4, 5};

    for (int n : items) {
        tree = insert(tree, n);
    }

    cout << "In-order: ";
    inOrder(tree);
    cout << "\n";

    cout << "Pre-order: ";
    preOrder(tree);
    cout << "\n";

    cout << "Post-order: ";
    postOrder(tree);
    cout << "\n";

    return 0;
}