#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

class item {
public:
    string name;
    double price;
    int quantity;

    item(string n, double p, int q) : name(n), price(p), quantity(q) {}
};

class order_processor {
public:
    double process_order(const vector<item>& cart, const string& customer_type, const string& payment_method) {
        
        for (const auto& current_item : cart) {
            if (current_item.quantity <= 0) return -1.0; 
        }

        double total_amount = 0;
        for (const auto& current_item : cart) {
            total_amount += current_item.price * current_item.quantity;
        }

        double discount = 0;
        if (customer_type == "vip") {
            discount = total_amount * 0.20;
        } else if (customer_type == "student") {
            discount = total_amount * 0.10;
        } else if (customer_type == "regular") {
            if (total_amount > 1000.0) {
                discount = total_amount * 0.05;
            }
        }

        if (payment_method != "credit_card" && payment_method != "paypal" && payment_method != "cash") {
            return -1.0; 
        }

        return total_amount - discount;
    }
};

bool is_equal(double a, double b) {
    return std::abs(a - b) < 0.01;
}

void run_all_tests() {
    order_processor processor;

    cout << "Running unit tests..." << endl;

    // 1. VIP знижки (20% від 1000 = 800)
    vector<item> cart_vip = { item("Laptop", 1000.0, 1) };
    assert(is_equal(processor.process_order(cart_vip, "vip", "credit_card"), 800.0));
    cout << "[OK] Test 1: VIP customer" << endl;

    // 2. студентська знижка (10% від 500 = 450)
    vector<item> cart_student = { item("Phone", 500.0, 1) };
    assert(is_equal(processor.process_order(cart_student, "student", "cash"), 450.0));
    cout << "[OK] Test 2: Student customer" << endl;

    // 3. клієнт без знижки (сума <= 1000)
    vector<item> cart_regular_no_discount = { item("Mouse", 800.0, 1) };
    assert(is_equal(processor.process_order(cart_regular_no_discount, "regular", "paypal"), 800.0));
    cout << "[OK] Test 3: Regular customer (no discount)" << endl;

    // 4. клієнт зі знижкою за обсяг (5% від 1200 = 1140)
    vector<item> cart_regular_discount = { item("Monitor", 1200.0, 1) };
    assert(is_equal(processor.process_order(cart_regular_discount, "regular", "credit_card"), 1140.0));
    cout << "[OK] Test 4: Regular customer (volume discount)" << endl;

    // 5. помилка наявності товару (quantity = 0)
    vector<item> cart_empty_stock = { item("Keyboard", 100.0, 0) };
    assert(is_equal(processor.process_order(cart_empty_stock, "regular", "cash"), -1.0));
    cout << "[OK] Test 5: Item out of stock" << endl;

    // 6. невідомий метод оплати
    vector<item> cart_bad_payment = { item("Tablet", 300.0, 1) };
    assert(is_equal(processor.process_order(cart_bad_payment, "regular", "bitcoin"), -1.0));
    cout << "[OK] Test 6: Invalid payment method" << endl;

    cout << "All unit tests passed successfully!" << endl;
}

int main() {
    run_all_tests();
    return 0;
}