#pragma once
#include <string>

/**
 * @brief Class representing an item in the store.
 * * Stores basic information about a product, such as its name, 
 * unit price, and the quantity added to the cart.
 */

class item 
{
public:
    std::string name; ///< Name of the item
    double price;     ///< Price per unit
    int quantity;     ///< Ordered quantity

    /**
     * @brief Constructor to initialize an item.
     * * @param n Name of the item.
     * @param p Price per unit of the item.
     * @param q Quantity of the item.
     */
    
    item(std::string n, double p, int q) : name(n), price(p), quantity(q) {}
};