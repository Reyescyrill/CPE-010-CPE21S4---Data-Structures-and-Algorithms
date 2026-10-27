#ifndef PRINTER_H
#define PRINTER_H

#include "Node.h"
#include <string>

class Printer {
private:
    Node* frontPtr{nullptr};
    Node* backPtr{nullptr};
    int jobCount{0};

public:
    Printer() = default;
    ~Printer();

    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;

    [[nodiscard]] bool isEmpty() const;
    void addJob(int id, const std::string& userName, int pages);
    void processNextJob();
    void processAllJobs();
    void displayQueue() const;
};

#endif