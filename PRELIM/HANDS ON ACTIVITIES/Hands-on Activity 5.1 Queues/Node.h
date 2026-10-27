#ifndef NODE_H
#define NODE_H

#include "Job.h"

struct Node {
    Job job;
    Node* next;

    explicit Node(Job j) : job(std::move(j)), next(nullptr) {}
};

#endif