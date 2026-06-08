#pragma once

/**
 * @brief Base interface for discount calculation algorithms.
 * * This interface implements the Strategy pattern, allowing dynamic 
 * changes to the discount logic without modifying the core processor code.
 */

class discount_strategy 
{
public:
    /**
     * @brief Calculates the discount amount based on the total cost.
     * * @param total_amount Total order amount before discounts.
     * @return Discount amount (double).
     */

    virtual double calculate_discount(double total_amount) const = 0;
    virtual ~discount_strategy() = default;
};

/**
 * @brief Discount strategy for VIP customers.
 * Provides a fixed 20% discount on the total amount.
 */

class vip_discount : public discount_strategy 
{
public:
    double calculate_discount(double total_amount) const override 
    {
        return total_amount * 0.20; 
    }
};

/**
 * @brief Discount strategy for students.
 * Provides a fixed 10% discount on the total amount.
 */

class student_discount : public discount_strategy 
{
public:
    double calculate_discount(double total_amount) const override 
    {
        return total_amount * 0.10; 
    }
};

/**
 * @brief Discount strategy for regular customers.
 * Provides a 5% discount only if the order amount exceeds 1000.
 */

class regular_discount : public discount_strategy 
{
public:
    double calculate_discount(double total_amount) const override 
    {
        return (total_amount > 1000.0) ? total_amount * 0.05 : 0.0;
    }
};