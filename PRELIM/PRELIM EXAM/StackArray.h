#ifndef STACKARRAY_H
#define STACKARRAY_H

#define MAX 100

class StackArray {
private:
    int arr[MAX];
    int top;

public:
    StackArray() {
        top = -1;
    }

    void push(int num) {
        if (top < MAX - 1) {
            top++;
            arr[top] = num;
        }
    }

    int pop() {
        if (top >= 0) {
            int value = arr[top];
            top--;
            return value;
        }
        return -1;
    }

    bool isEmpty() {
        if (top < 0) {
            return true;
        }
        return false;
    }
};

#endif