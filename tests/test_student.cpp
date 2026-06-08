#include <iostream>
#include <vector>
#include <cassert>
#include "test_registry.h"
#include "../include/item.h"
#include "../include/discount_strategy.h"
#include "../include/payment_strategy.h"
#include "../include/order_processor.h"

using namespace std;

void run_test_student() 
{
    order_processor processor;
    student_discount student;
    cash_payment cash;

    vector<item> cart = { item("Phone", 500.0, 1) };
    assert(is_equal(processor.process_order(cart, &student, &cash), 450.0));
    cout << "[OK] Test: Student customer with Cash" << endl;
}