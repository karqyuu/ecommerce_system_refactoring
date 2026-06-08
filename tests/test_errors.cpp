#include <iostream>
#include <vector>
#include <cassert>
#include "test_registry.h"
#include "../include/item.h"
#include "../include/discount_strategy.h"
#include "../include/payment_strategy.h"
#include "../include/order_processor.h"

using namespace std;

void run_test_errors() 
{
    order_processor processor;
    regular_discount regular;
    cash_payment cash;

    // помилка наявності
    vector<item> cart_empty_stock = { item("Keyboard", 100.0, 0) };
    assert(is_equal(processor.process_order(cart_empty_stock, &regular, &cash), -1.0));
    cout << "[OK] Test: Item out of stock handled correctly" << endl;

    // помилка методу оплати
    vector<item> cart_no_payment = { item("Tablet", 300.0, 1) };
    assert(is_equal(processor.process_order(cart_no_payment, &regular, nullptr), -1.0));
    cout << "[OK] Test: Missing payment method handled correctly" << endl;
}