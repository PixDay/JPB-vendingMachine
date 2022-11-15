/* CODE OF INVENTORY MANAGER */

#include "InventoryManager.hpp"

InventoryManager::InventoryManager(/* args */)
{
}

InventoryManager::~InventoryManager()
{
}

// GETTERS
uint32_t InventoryManager::getQuantityOfProducts() {
    return this->products_.size();
}

uint32_t InventoryManager::getQuantityOf(uint32_t id) {
    // Get index of product
    uint32_t index = 0;
    for (auto &product : this->products_) {
        if (product.getId() == id) {
            break;
        }
        index++;
    }

    // Return quantity of product
    return this->productQuantities_[index];
}

uint32_t InventoryManager::getQuantityOf(std::string name) {
    uint32_t index = 0;
    // Loop over products to get the quantity of desired product
    for (auto product : products_) {
        if (product.getName() == name) {
            break;
        }
        index++;
    }
    return this->productQuantities_[index];
}

Product InventoryManager::getProduct(uint32_t id) {
    // Loop over products to get the desired product
    for (auto product : products_) {
        if (product.getId() == id) {
            return product;
        }
    }
    // If product not found, return an empty product
    return Product(-1, 0.0, "");
}

Product InventoryManager::getProduct(std::string name) {
    // Loop over products to get the desired product
    for (auto product : products_) {
        std::string tmp = product.getName();
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c){ return std::tolower(c); });
        if (tmp == name) {
            return product;
        }
    }
    // If product not found, return an empty product
    return Product(-1, 0.0, "");
}

// SETTERS
void InventoryManager::setQuantityOf(uint32_t id, uint32_t quantity) {
    // Loop over products to get the quantity of desired product
    for (auto product : products_) {
        if (product.getId() == id) {
            productQuantities_[product.getId()] = quantity;
        }
    }
}

void InventoryManager::setQuantityOf(std::string name, uint32_t quantity) {
    // Loop over products to get the quantity of desired product
    for (auto product : products_) {
        if (product.getName() == name) {
            productQuantities_[product.getId()] = quantity;
        }
    }
}

// ADDERS
void InventoryManager::addProduct(Product product, uint32_t quantity) {
    // Add product to products vector
    this->products_.push_back(product);
    // Add quantity to productQuantities vector
    this->productQuantities_.push_back(quantity);
}

void InventoryManager::addProduct(Product product) {
    // Add product to products vector
    this->products_.push_back(product);
    // Add quantity to productQuantities vector
    this->productQuantities_.push_back(1);
}

// REMOVERS
uint32_t InventoryManager::removeProduct(uint32_t id) {
    size_t index = 0;
    // Loop over products to get the quantity of desired product
    for (auto product : products_) {
        if (product.getId() == id) {
            productQuantities_[index]--;
            return 0;
        }
        index++;
    }
    return 1;
}

// SHOWERS
void InventoryManager::showProducts(void) {
    // Loop over products to get the quantity of desired product
    for (auto product : products_) {
        std::cout << "Product: " << product.getName() << " - Quantity: " << productQuantities_[product.getId()] << " - Price: " << product.getPrice() << "$" << std::endl;
    }
}
