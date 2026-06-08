#pragma once

class discount_strategy 
{
public:
    virtual double calculate_discount(double total_amount) const = 0;
    virtual ~discount_strategy() = default;
};

class vip_discount : public discount_strategy 
{
public:
    double calculate_discount(double total_amount) const override 
    {
        return total_amount * 0.20; 
    }
};

class student_discount : public discount_strategy 
{
public:
    double calculate_discount(double total_amount) const override 
    {
        return total_amount * 0.10; 
    }
};

class regular_discount : public discount_strategy 
{
public:
    double calculate_discount(double total_amount) const override 
    {
        return (total_amount > 1000.0) ? total_amount * 0.05 : 0.0;
    }
};