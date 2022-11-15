#include <iostream>
#include <string>
#include <cstdint>

// Include vending machine core
#include "VendingMachineCore.hpp"

// main function
int main()
{
    VendingMachineCore vendingMachineCore;
    uint32_t error = vendingMachineCore.boot();
    if (error != 0)
    {
        std::cout << "Error: " << error << std::endl;
        return error;
    }
    return vendingMachineCore.start();
}