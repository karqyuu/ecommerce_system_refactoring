#pragma once
#include <iostream>

/**
 * @brief Base interface for payment methods.
 * * Implements the Strategy pattern to encapsulate various ways 
 * of processing payment transactions (cash, credit card, e-wallets).
 */

class payment_strategy 
{
public:
    /**
     * @brief Processes a transaction for the specified amount.
     * * @param amount Final amount to pay.
     * @return true if the payment was successful, false otherwise.
     */

    virtual bool process_payment(double amount) const = 0;
    virtual ~payment_strategy() = default;
};

/**
 * @brief Credit card payment strategy.
 * Simulates a connection to a banking gateway.
 */

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

/**
 * @brief PayPal payment strategy.
 * Simulates redirection to the payment system page.
 */

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

/**
 * @brief Cash on delivery payment strategy.
 */

class cash_payment : public payment_strategy 
{
public:
    bool process_payment(double amount) const override 
    {
        std::cout << "Cash payment. Prepare exact change for the courier.\n";
        return true;
    }
};