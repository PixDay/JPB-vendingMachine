/* INCLUDE OF PRODUCT */

#pragma once

#include <cstdint>
#include <iostream>

class Product
{
    private:
        uint32_t id_;
        double price_;
        std::string name_;
    public:
        Product(/* args */);
        Product(uint32_t id, double price, std::string name);
        ~Product();

        // GETTERS
        uint32_t getId() const;
        double getPrice() const;
        std::string getName();

        // SETTERS
        void setId(uint32_t id);
        void setPrice(uint32_t price);
        void setName(std::string name);

        // OPERATORS OVERLOADING
        bool operator!=(const Product& product) {
            // Compare products by name
            return this->name_ != product.name_;
        }

        bool operator==(const Product& product) {
            // Compare products by name
            return this->name_ == product.name_;
        }
};