#include <iostream>
#include <vector>
#include "../include/item.h"
#include "../include/discount_strategy.h"
#include "../include/payment_strategy.h"
#include "../include/order_processor.h"

using namespace std;

int main() 
{
    order_processor processor;

    // наповнення кошика 
    vector<item> my_cart = {
        item("Laptop", 25000.0, 1),
        item("Wireless Mouse", 800.0, 2)
    };

    student_discount my_discount;
    paypal_payment my_payment;

    cout << "--- Starting new order ---" << endl;

    double final_price = processor.process_order(my_cart, &my_discount, &my_payment);

    if (final_price != -1.0) {
        cout << "--- Order successfully placed! Final cost: " << final_price << " UAH ---" << endl;
    } else {
        cout << "--- Order failed! ---" << endl;
    }

    return 0;
}