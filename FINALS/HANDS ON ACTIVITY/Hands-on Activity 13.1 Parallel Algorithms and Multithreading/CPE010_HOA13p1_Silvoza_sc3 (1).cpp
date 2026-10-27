#include <iostream>
#include <thread>

int global_var = 0;
void add(int value) {
    global_var += value;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    // DISPLAY
    std::cout << "Initial Display: " << global_var << std::endl;

    // JOIN T1
    T1.join();
    std::cout << "Display after T1.join(): " << global_var << std::endl;

    // JOIN T2
    T2.join();
    std::cout << "Display after T2.join(): " << global_var << std::endl;

    // JOIN T3
    T3.join();
    std::cout << "Display after T3.join(): " << global_var << std::endl;

    return 0;
}