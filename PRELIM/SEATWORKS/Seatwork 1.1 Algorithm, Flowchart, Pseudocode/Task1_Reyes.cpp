#include <iostream>
using namespace std;

int main() {
    float quiz1, quiz2, quiz3;
    float total, average;

    cout << "Enter Quiz 1: ";
    cin >> quiz1;

    cout << "Enter Quiz 2: ";
    cin >> quiz2;

    cout << "Enter Quiz 3: ";
    cin >> quiz3;

    total = quiz1 + quiz2 + quiz3;
    average = total / 3;

    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;

    return 0;
}