#include <iostream>
#include <thread>

using namespace std;

int sum1 = 0;
int sum2 = 0;
int arr[6] = {10, 20, 30, 40, 50, 60};

void addFirstHalf() {
    for (int i = 0; i < 3; i++) {
        sum1 += arr[i];
    }
}

void addSecondHalf() {
    for (int i = 3; i < 6; i++) {
        sum2 += arr[i];
    }
}

int main() {
    thread t1(addFirstHalf);
    thread t2(addSecondHalf);

    t1.join();
    t2.join();

    int total = sum1 + sum2;

    cout << "First half sum: " << sum1 << endl;
    cout << "Second half sum: " << sum2 << endl;
    cout << "Total sum: " << total << endl;

    return 0;
}