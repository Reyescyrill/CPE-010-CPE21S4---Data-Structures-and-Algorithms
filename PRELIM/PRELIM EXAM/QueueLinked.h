#ifndef QUEUELINKED_H
#define QUEUELINKED_H

struct Node {
    int data;
    Node* next;
};

class QueueLinked {
private:
    Node* front;
    Node* rear;

public:
    QueueLinked() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int num) {
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            return -1;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    bool isEmpty() {
        if (front == nullptr) {
            return true;
        }
        return false;
    }
};

#endif