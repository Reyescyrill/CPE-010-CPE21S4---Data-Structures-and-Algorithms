#include <iostream>
#include <sstream>
#include <string>
#include "StackArray.h"
#include "QueueLinked.h"

using namespace std;

bool checkSequence(string input) {
    StackArray myStack;
    QueueLinked myQueue;

    int number;
    stringstream ss(input);

    
    while (ss >> number) {
        myStack.push(number);
        myQueue.enqueue(number);
    }

    
    while (!myStack.isEmpty() && !myQueue.isEmpty()) {
        int fromStack = myStack.pop();
        int fromQueue = myQueue.dequeue();

        if (fromStack != fromQueue) {
            return false;
        }
    }

    return true;
}

int main() {
    string testCases[] = {
        "101 102 103 102 101",
        "101 102 103",
        "205 205",
        "501",
        "10 20 30 40 50",
        "11 22 33 22 11"
    };

    cout << "Customer Numbers\t\tValid?\n";
    cout << "----------------------------\n";

    for (int i = 0; i < 6; i++) {
        bool result = checkSequence(testCases[i]);
        cout << testCases[i] << "\t\t";
        
        if (result == true) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}