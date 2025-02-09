#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//Base Class
class product {
    const string _name;
    const double _price;

public:
    //Constructor
    product(const string &n, double p):
    _name(n), _price(p){}

    //Virtual Destructor
    virtual ~product() {}

    //Virtual function to allow overriding
    virtual string printDetails() const {
        return _name;
    }

    //Getter for price
    double getPrice() const {
        return _price;
    }
};

//Derived Class
class Book : public product {
    string _isbn;

public:
    Book(const string &n, double p, const string &i): product(n,p), _isbn(i){}

    string printDetails() const override {
        return '"' + product::printDetails() + '"' + ", ISBN " + _isbn;
    }
};


// Abstract Class
class Pricing {
public:
    virtual double calculateCost(double price, int quantity) const = 0; // Pure virtual function
    virtual ~Pricing() {} // Virtual destructor
};

// Simple Derived Class
class SimplePricing : public Pricing {
public:
    double calculateCost(double price, int quantity) const override {
        return price * quantity;
    }
};

// Discount Pricing Class
class DiscountPricing : public Pricing {
    int threshold;
    double discount;

public:
    DiscountPricing(int t, double d) : threshold(t), discount(d) {}

    double calculateCost(double price, int quantity) const override {
        return (quantity >= threshold) ? price * quantity * (1 - discount) : price * quantity;
    }
};

// Composite Pricing Class
class CompositePricing : public Pricing {
    const Pricing& policy1;
    const Pricing& policy2;

public:
    CompositePricing(const Pricing& p1, const Pricing& p2) : policy1(p1), policy2(p2) {}

    double calculateCost(double price, int quantity) const override {
        return std::min(policy1.calculateCost(price, quantity),
                        policy2.calculateCost(price, quantity));
    }
};

// Function to Print Bill
void printBill(const Pricing& policy, double price, int quantity) {
    cout << "Total Cost: " << policy.calculateCost(price, quantity) << " USD\n";
}

// Main Function with Examples
int main() {
    SimplePricing simplePolicy;
    DiscountPricing discountPolicy(10, 0.1); // 10% discount for 10+ items
    CompositePricing compositePolicy(simplePolicy, discountPolicy);

    cout << "Simple Pricing:\n";
    printBill(simplePolicy, 10.0, 5); // Output: Total Cost: 50 USD

    cout << "Discount Pricing:\n";
    printBill(discountPolicy, 10.0, 12); // Output: Total Cost: 108 USD

    cout << "Composite Pricing:\n";
    printBill(compositePolicy, 10.0, 12); // Output: Total Cost: 108 USD (chooses the cheaper policy)

    return 0;
}


void delete_zereos(vector<double> &v) {
    auto it = v.begin();
    while (it != v.end()) {
        if (*it == 0) {
            it = v.erase(it);
        }
        else {
            ++it;
        }
    }
}



//2023
//1
// 24     3, 16

void doubling(list<double> &l) {
    for (auto &x : l) {

    }
}