#pragma once
#include <iostream>

class payment_strategy 
{
public:
    virtual bool process_payment(double amount) const = 0;
    virtual ~payment_strategy() = default;
};

class credit_card_payment : public payment_strategy 
{
public:
    bool process_payment(double amount) const override 
    {
        std::cout << "Connecting to banking gateway...\n";
        std::cout << "Payment of " << amount << " UAH via credit card successful.\n";
        return true;
    }
};

class paypal_payment : public payment_strategy 
{
public:
    bool process_payment(double amount) const override 
    {
        std::cout << "Redirecting to PayPal...\n";
        std::cout << "Payment of " << amount << " UAH via PayPal successful.\n";
        return true;
    }
};

class cash_payment : public payment_strategy 
{
public:
    bool process_payment(double amount) const override 
    {
        std::cout << "Cash payment. Prepare exact change for the courier.\n";
        return true;
    }
};