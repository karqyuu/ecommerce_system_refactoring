#pragma once
#include <string>

class item 
{
public:
    std::string name;
    double price;
    int quantity;

    item(std::string n, double p, int q) : name(n), price(p), quantity(q) {}
};