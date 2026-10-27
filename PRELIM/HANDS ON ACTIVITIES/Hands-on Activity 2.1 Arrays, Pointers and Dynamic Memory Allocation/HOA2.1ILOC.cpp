#include <iostream>
#include <string>

using namespace std;

// Fruit Class
class Fruit {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Fruit(string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Fruit() {
        cout << "Fruit Destructor Called." << endl;
    }

    // Copy Constructor
    Fruit(const Fruit &f) {
        name = f.name;
        price = f.price;
        quantity = f.quantity;
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit &f) {
        if (this != &f) {
            name = f.name;
            price = f.price;
            quantity = f.quantity;
        }
        return *this;
    }

    double calculateSum() {
        return price * quantity;
    }

    void display() {
        cout << "Fruit: " << name
             << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum() << endl;
    }
};

// Vegetable Class
class Vegetable {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Vegetable(string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Vegetable() {
        cout << "Vegetable Destructor Called." << endl;
    }

    // Copy Constructor
    Vegetable(const Vegetable &v) {
        name = v.name;
        price = v.price;
        quantity = v.quantity;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable &v) {
        if (this != &v) {
            name = v.name;
            price = v.price;
            quantity = v.quantity;
        }
        return *this;
    }

    double calculateSum() {
        return price * quantity;
    }

    void display() {
        cout << "Vegetable: " << name
             << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum() << endl;
    }
};

// Total Sum Function
double TotalSum(Fruit *apple, Fruit *banana,
                Vegetable *broccoli, Vegetable *lettuce) {

    double total = 0;

    if (apple) total += apple->calculateSum();
    if (banana) total += banana->calculateSum();
    if (broccoli) total += broccoli->calculateSum();
    if (lettuce) total += lettuce->calculateSum();

    return total;
}

int main() {

    // Grocery List
    Fruit *apple = new Fruit("Apple", 10, 7);
    Fruit *banana = new Fruit("Banana", 10, 8);
    Vegetable *broccoli = new Vegetable("Broccoli", 60, 12);
    Vegetable *lettuce = new Vegetable("Lettuce", 50, 10);

    cout << "===== Jenna's Grocery List =====\n\n";

    apple->display();
    banana->display();
    broccoli->display();
    lettuce->display();

    cout << "\nTotal Amount: PHP "
         << TotalSum(apple, banana, broccoli, lettuce)
         << endl;

    // Delete Lettuce
    delete lettuce;
    lettuce = NULL;

    cout << "\nAfter Removing Lettuce\n";

    cout << "Updated Total: PHP "
         << TotalSum(apple, banana, broccoli, lettuce)
         << endl;

    // Free remaining memory
    delete apple;
    delete banana;
    delete broccoli;

    return 0;
}