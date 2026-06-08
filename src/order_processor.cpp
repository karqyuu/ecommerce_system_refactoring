#include "../include/order_processor.h"
#include <iostream>

using namespace std;

double order_processor::process_order(const vector<item>& cart, 
                                      const discount_strategy* discount, 
                                      const payment_strategy* payment) 
{
    
    // наявність та підрахунок суми
    double total_amount = 0;
    for (const auto& current_item : cart) 
    {
        if (current_item.quantity <= 0) 
        {
            cout << "Error: Item " << current_item.name << " is out of stock.\n";
            return -1.0; 
        }
        total_amount += current_item.price * current_item.quantity;
    }

    // розрахунок знижки
    double discount_amount = 0;
    if (discount != nullptr) 
    {
        discount_amount = discount->calculate_discount(total_amount);
    }
    double final_amount = total_amount - discount_amount;

    // оплата 
    if (payment != nullptr) 
    {
        if (!payment->process_payment(final_amount)) 
        {
            return -1.0; // помилка оплати
        }
    } else 
    {
        cout << "Error: No payment method provided.\n";
        return -1.0;
    }

    return final_amount;
}