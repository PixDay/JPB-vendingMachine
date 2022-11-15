/* CODE OF PRODUCT */

#include "Product.hpp"

Product::Product()
{
}

Product::Product(uint32_t id, double price, std::string name):
    id_(id),
    price_(price),
    name_(name)
{
}


Product::~Product()
{
}

// GETTERS
uint32_t Product::getId() const
{
    return id_;
}

double Product::getPrice() const
{
    return price_;
}

std::string Product::getName()
{
    return name_;
}

// SETTERS

void Product::setId(uint32_t id)
{
    id_ = id;
}

void Product::setPrice(uint32_t price)
{
    price_ = price;
}

void Product::setName(std::string name)
{
    name_ = name;
}
