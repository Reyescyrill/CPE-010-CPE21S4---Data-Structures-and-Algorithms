#include <iostream>
#include <thread>
#include <chrono>

// Global variable of type integer
int global_var = 0;

// Function that adds a given value to the global variable
void add(int val) {
    // Small delay to simulate processing time across threads
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    global_var += val;
}

int main() {
    // Create 3 threads and pass the add function with different integer values
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Display 1 (Before T1.join()): Global Variable = " << global_var << std::endl;
    T1.join();

    std::cout << "Display 2 (After T1.join()):  Global Variable = " << global_var << std::endl;
    T2.join();

    std::cout << "Display 3 (After T2.join()):  Global Variable = " << global_var << std::endl;
    T3.join();

    std::cout << "Display 4 (After T3.join()):  Global Variable = " << global_var << std::endl;

    return 0;
}