#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayQueue {
private:
    int* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    // (constructor) Construct queue
    ArrayQueue(int capacity = 8) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        q_array = new int[q_capacity];
    }

    // Copy Constructor
    ArrayQueue(const ArrayQueue& other) 
        : q_capacity(other.q_capacity), q_size(other.q_size), q_front(other.q_front), q_back(other.q_back) {
        q_array = new int[q_capacity];
        for (int i = 0; i < q_capacity; ++i) {
            q_array[i] = other.q_array[i];
        }
    }

    // Copy Assignment Operator
    ArrayQueue& operator=(const ArrayQueue& other) {
        if (this != &other) {
            delete[] q_array;
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new int[q_capacity];
            for (int i = 0; i < q_capacity; ++i) {
                q_array[i] = other.q_array[i];
            }
        }
        return *this;
    }

    // Destructor
    ~ArrayQueue() {
        delete[] q_array;
    }

    // Test whether container is empty
    bool Empty() const {
        return q_size == 0;
    }

    // Return size
    int Size() const {
        return q_size;
    }

    // Sets queue size back to 0 and resets q_front and q_back
    void Clear() {
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Access next element (front)
    int Front() const {
        if (Empty()) throw runtime_error("Queue is empty");
        return q_array[q_front];
    }

    // Access last element (back)
    int Back() const {
        if (Empty()) throw runtime_error("Queue is empty");
        return q_array[q_back];
    }

    // Insert element
    void Enqueue(int val) {
        if (q_size == q_capacity) {
            cout << "Queue is full! Cannot enqueue " << val << "\n";
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = val;
        q_size++;
    }

    // Remove next element
    void Dequeue() {
        if (Empty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        q_front = (q_front + 1) % q_capacity;
        q_size--;
        if (q_size == 0) {
            q_front = 0;
            q_back = -1;
        }
    }

    void Display() const {
        if (Empty()) {
            cout << "[ Empty Queue ]\n";
            return;
        }
        for (int i = 0; i < q_size; ++i) {
            int index = (q_front + i) % q_capacity;
            cout << q_array[index] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ArrayQueue aq(8);

    cout << "1. Enqueue operations (10, 20, 30, 40, 50):\n";
    aq.Enqueue(10);
    aq.Enqueue(20);
    aq.Enqueue(30);
    aq.Enqueue(40);
    aq.Enqueue(50);
    cout << "Queue: "; aq.Display();
    cout << "Size: " << aq.Size() << "\n";
    cout << "Front: " << aq.Front() << "\n";
    cout << "Back: " << aq.Back() << "\n";

    cout << "\n2. Dequeue operation:\n";
    aq.Dequeue();
    cout << "Queue after Dequeue: "; aq.Display();

    cout << "\n3. Copy Constructor:\n";
    ArrayQueue aqCopy = aq;
    cout << "Copied Queue: "; aqCopy.Display();

    cout << "\n4. Copy Assignment Operator:\n";
    ArrayQueue aqAssign(5);
    aqAssign = aq;
    cout << "Assigned Queue: "; aqAssign.Display();

    cout << "\n5. Clear operation:\n";
    aq.Clear();
    cout << "Is Empty after Clear? " << (aq.Empty() ? "True" : "False") << "\n";

    return 0;
}