#include<iostream>
#include <stack>


int main(){

// push
// pop
//isEmpty
//isFull
//Top
// create
std::stack<char> stack1;

std::cout<<"Is the stack empty?"<<stack1.empty() <<std::endl;
stack1.push('C');
std::cout<<"current top of the stack: "<<stack1.top() <<std::endl;
stack1.push('Y');
std::cout<<"current top of the stack: "<<stack1.top() <<std::endl;
std::cout<<"Is the stack empty?"<<stack1.empty() <<std::endl;
std::cout<<"What is the size of the stack? "<<stack1.size() <<std::endl;

//swap

//emplace
    return 0;
}