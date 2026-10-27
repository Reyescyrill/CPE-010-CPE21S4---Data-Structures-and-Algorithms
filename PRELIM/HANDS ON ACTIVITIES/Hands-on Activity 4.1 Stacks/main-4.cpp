#include <iostream>
#include "stackList.h"

int main() {
    std::cout << "--- Testing Stack Operations ---\n\n";

    // Pushing elements
    push<int>(05);
    push<int>(14);
    push<int>(06);

    // Displaying current top
    Top<int>();

    // Displaying all elements
    displayALL<int>();

    // Popping an element
    std::cout << "Popped value: " << pop<int>() << "\n\n";

    // Displaying stack after pop
    displayALL<int>();

    return 0;
}