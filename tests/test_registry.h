#pragma once
#include <cmath>

inline bool is_equal(double a, double b) 
{
    return std::abs(a - b) < 0.01;
}

void run_test_vip();
void run_test_student();
void run_test_regular();
void run_test_errors();