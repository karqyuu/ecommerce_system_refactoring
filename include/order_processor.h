#pragma once
#include <vector>
#include "item.h"
#include "discount_strategy.h"
#include "payment_strategy.h"

/**
 * @brief Main class for coordinating the order processing workflow.
 * * This class adheres to the Single Responsibility Principle (SRP). 
 * It does not contain hardcoded calculation or payment logic, but rather 
 * coordinates the interaction between the shopping cart and the injected strategies.
 */

class order_processor 
{
public:
    /**
     * @brief Processes the order: checks stock, applies the discount, and processes the payment.
     * * @param cart Collection (vector) of item objects the customer wishes to purchase.
     * @param discount Pointer to a discount strategy object (nullptr is allowed).
     * @param payment Pointer to a payment strategy object.
     * * @return Final order cost on success. Returns -1.0 if an item is out of stock or a payment error occurs.
     */
    
    double process_order(const std::vector<item>& cart, 
                         const discount_strategy* discount, 
                         const payment_strategy* payment);
};