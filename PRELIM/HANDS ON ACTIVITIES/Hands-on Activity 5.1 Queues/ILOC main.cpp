#include "Printer.h"
#include <iostream>

int main() {
    Printer sharedPrinter;

    std::cout << "=====================================================\n";
    std::cout << "    ILO C: SHARED PRINTER SIMULATION USING QUEUE     \n";
    std::cout << "=====================================================\n\n";

    std::cout << "--- Phase 1: Users submitting initial print requests ---\n";
    sharedPrinter.addJob(101, "Alice", 12);
    sharedPrinter.addJob(102, "Bob", 5);
    sharedPrinter.addJob(103, "Charlie", 25);
    sharedPrinter.addJob(104, "David", 3);

    sharedPrinter.displayQueue();

    std::cout << "--- Phase 2: Printer begins servicing jobs ---\n";
    sharedPrinter.processNextJob();
    sharedPrinter.processNextJob();

    sharedPrinter.displayQueue();

    std::cout << "--- Phase 3: New incoming print request ---\n";
    sharedPrinter.addJob(105, "Eva", 8);

    sharedPrinter.processAllJobs();
}