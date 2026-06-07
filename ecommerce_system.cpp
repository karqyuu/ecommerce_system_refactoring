#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Простий клас для зберігання даних про товар
class item {
public:
    string name;
    double price;
    int quantity;

    item(string n, double p, int q) : name(n), price(p), quantity(q) {}
};

// "Поганий" клас
class order_processor {
public:
    void process_order(const vector<item>& cart, const string& customer_type, const string& payment_method) {
        cout << "--- Order processing started ---" << endl;

        // 1. Перевірка наявності 
        for (const auto& current_item : cart) {
            if (current_item.quantity <= 0) {
                cout << "Error: Item " << current_item.name << " is out of stock." << endl;
                return;
            }
        }

        // 2. Підрахунок загальної суми
        double total_amount = 0;
        for (const auto& current_item : cart) {
            total_amount += current_item.price * current_item.quantity;
        }

        // 3. Застосування знижок 
        double discount = 0;
        if (customer_type == "vip") {
            discount = total_amount * 0.20; 
            cout << "Applied VIP discount: 20%" << endl;
        } else if (customer_type == "student") {
            discount = total_amount * 0.10; 
            cout << "Applied student discount: 10%" << endl;
        } else if (customer_type == "regular") {
            if (total_amount > 1000.0) {
                discount = total_amount * 0.05; 
                cout << "Applied volume discount: 5%" << endl;
            }
        }

        double final_amount = total_amount - discount;
        cout << "Total to pay: " << final_amount << " UAH" << endl;

        // 4. Логіка оплати 
        if (payment_method == "credit_card") {
            cout << "Connecting to the banking gateway..." << endl;
            cout << "Payment of " << final_amount << " UAH via credit card was successful." << endl;
        } else if (payment_method == "paypal") {
            cout << "Redirecting to PayPal page..." << endl;
            cout << "Payment of " << final_amount << " UAH via PayPal was successful." << endl;
        } else if (payment_method == "cash") {
            cout << "Cash payment. Please prepare exact change for the courier." << endl;
        } else {
            cout << "Error: Unknown payment method." << endl;
            return;
        }

        cout << "--- Order successfully placed! ---\n" << endl;
    }
};

int main() {
    order_processor processor;

    // Створюємо тестовий кошик
    vector<item> test_cart = {
        item("Laptop", 25000.0, 1),
        item("Mouse", 800.0, 2)
    };

    // Тестовий запуск
    processor.process_order(test_cart, "vip", "credit_card");

    return 0;
}