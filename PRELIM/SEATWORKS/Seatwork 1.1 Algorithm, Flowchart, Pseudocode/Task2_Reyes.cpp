#include <iostream>
using namespace std;

int main() {

    float item1, item2, item3;
    float total, payment, change;

    cout << "Enter price of Item 1: ";
    cin >> item1;

    cout << "Enter price of Item 2: ";
    cin >> item2;

    cout << "Enter price of Item 3: ";
    cin >> item3;

    total = item1 + item2 + item3;

    cout << "\n--- TRANSACTION DETAILS ---" << endl;
    cout << "Item 1: " << item1 << endl;
    cout << "Item 2: " << item2 << endl;
    cout << "Item 3: " << item3 << endl;
    cout << "Total Price: " << total << endl;

    cout << "\nEnter Payment: ";
    cin >> payment;

    change = payment - total;

    cout << "Payment: " << payment << endl;
    cout << "Change: " << change << endl;

    return 0;
}