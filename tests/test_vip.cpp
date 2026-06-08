#include <iostream>
#include <vector>
#include <cassert>
#include "test_registry.h"
#include "../include/item.h"
#include "../include/discount_strategy.h"
#include "../include/payment_strategy.h"
#include "../include/order_processor.h"

using namespace std;

void run_test_vip() 
{
    order_processor processor;
    vip_discount vip;
    credit_card_payment card;

    vector<item> cart = { item("Laptop", 1000.0, 1) };
    assert(is_equal(processor.process_order(cart, &vip, &card), 800.0));
    cout << "[OK] Test: VIP customer with Credit Card" << endl;
}