#include <iostream>
#include <string>
#include <thread>

using namespace std;

void print(int n, const string &str) {
    cout << "Printing integer: " << n << endl;
    cout << "Printing string: " << str << endl;

}

int main (){
    thread t1(print, 10, "T.I.P");
    t1.join();

    return 0;

}