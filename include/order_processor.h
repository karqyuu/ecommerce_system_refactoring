#pragma once
#include <vector>
#include "item.h"
#include "discount_strategy.h"
#include "payment_strategy.h"

class order_processor 
{
public:
    double process_order(const std::vector<item>& cart, 
                         const discount_strategy* discount, 
                         const payment_strategy* payment);
};