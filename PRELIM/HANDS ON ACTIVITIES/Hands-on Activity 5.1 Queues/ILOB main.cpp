#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* frontPtr;
    Node* backPtr;

public:
    LinkedListQueue() : frontPtr(nullptr), backPtr(nullptr) {}

    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    // Algorithm: Inserting an item into a queue
    void enqueue(int val) {
        Node* newPtr = new Node(val);
        if (isEmpty()) {
            // Algorithm for empty queue:
            frontPtr = newPtr;
            backPtr = newPtr;
        } else {
            // Algorithm for non-empty queue:
            newPtr->next = nullptr;
            backPtr->next = newPtr;
            backPtr = newPtr;
        }
    }

    // Algorithm: Deleting an item from a queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* tempPtr = nullptr;
        if (frontPtr == backPtr) {
            // Algorithm for queue with 1 item:
            tempPtr = frontPtr;
            frontPtr = nullptr;
            backPtr = nullptr;
            delete tempPtr;
        } else {
            // Algorithm for queue with >1 items:
            tempPtr = frontPtr;
            frontPtr = frontPtr->next;
            tempPtr->next = nullptr;
            delete tempPtr;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "[ Empty Queue ]\n";
            return;
        }
        Node* curr = frontPtr;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedListQueue q;

    cout << "1. Inserting item into empty queue (enqueue 3):\n";
    q.enqueue(3);
    cout << "Queue contents: "; q.display();

    cout << "\n2. Inserting items into non-empty queue (enqueue 7, 1, 4, 2):\n";
    q.enqueue(7);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(2);
    cout << "Queue contents: "; q.display();

    cout << "\n3. Deleting item from queue of more than one item:\n";
    q.dequeue();
    cout << "Queue contents: "; q.display();

    cout << "\n4. Deleting items until 1 item remains:\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Queue contents: "; q.display();

    cout << "\n5. Deleting item from queue with one item:\n";
    q.dequeue();
    cout << "Queue contents: "; q.display();

    return 0;
}