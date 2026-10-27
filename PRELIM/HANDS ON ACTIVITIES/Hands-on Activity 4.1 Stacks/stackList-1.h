#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

// Class Node that contains data and pointer to the next node
template <typename T>
class Node {
public:
    T data;      
    Node* next;  
};

// Pointer for the top of the stack
template <typename T>
Node<T>* head = nullptr;

// STACK OPERATIONS

// push: Adds an element to the top of the stack
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

// pop: Removes and returns the top element of the stack
template <typename T>
T pop() {
    if (head<T> == nullptr) {
        std::cout << "Stack underflow!\n";
        return T();
    }
    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;
    delete temp;
    return tempVal;
}

// isEmpty: Checks if the stack is empty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// Top: Displays the value at the top of the stack
template <typename T>
void Top() {
    if (isEmpty<T>()) {
        std::cout << "Stack underflow\n";
        return;
    }
    std::cout << "Top of Stack: " << head<T>->data << std::endl;
}

// displayALL: Traverses and displays all elements in the stack
template <typename T>
void displayALL() {
    if (head<T> == nullptr) {
        std::cout << "stack underflow\n";
        return;
    }
    std::cout << "Displaying the stack:\n";
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << "\n";
}

#endif