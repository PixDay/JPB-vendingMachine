/* INCLUDE OF INVENTORY MANAGER */

#pragma once

#include <cstdint>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

// Include product
#include "Product.hpp"

class InventoryManager
{
    private:
        std::vector<Product> products_;
        std::vector<uint32_t> productQuantities_;

    public:
        InventoryManager(/* args */);
        ~InventoryManager();

        void addProduct(Product product, uint32_t quantity);
        void addProduct(Product product);
        uint32_t removeProduct(uint32_t id);
        void showProducts(void);

        // GETTERS
        uint32_t getQuantityOfProducts();
        uint32_t getQuantityOf(std::string);
        uint32_t getQuantityOf(uint32_t);
        Product getProduct(uint32_t);
        Product getProduct(std::string);

        // SETTERS
        void setQuantityOf(uint32_t id, uint32_t quantity);
        void setQuantityOf(std::string name, uint32_t quantity);
};