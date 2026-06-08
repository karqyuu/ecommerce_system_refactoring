#include <iostream>
#include <vector>
#include <cassert>
#include "test_registry.h"
#include "../include/item.h"
#include "../include/discount_strategy.h"
#include "../include/payment_strategy.h"
#include "../include/order_processor.h"

using namespace std;

void run_test_regular() 
{
    order_processor processor;
    regular_discount regular;
    paypal_payment paypal;
    credit_card_payment card;

    // без знижки
    vector<item> cart_no_discount = { item("Mouse", 800.0, 1) };
    assert(is_equal(processor.process_order(cart_no_discount, &regular, &paypal), 800.0));
    cout << "[OK] Test: Regular customer (no discount) with PayPal" << endl;

    // знижка за обсяг
    vector<item> cart_discount = { item("Monitor", 1200.0, 1) };
    assert(is_equal(processor.process_order(cart_discount, &regular, &card), 1140.0));
    cout << "[OK] Test: Regular customer (volume discount) with Credit Card" << endl;
}