/* INCLUDE OF MACHINE VENDING CORE */

#pragma once

#include <iostream>
#include <cstdint>
#include <cstring>

// Include of InputsManager
#include "InputsManager.hpp"
// Include of CashManager
#include "CashManager.hpp"
// Include of InventoryManager
#include "InventoryManager.hpp"

// State enum
enum State {
    INITIAL_STATE = 0,
    TREAT_INPUT = 1,
    CHECK_STOCK = 2,
    CHECK_CASH = 3,
    DISPENSE_PRODUCT = 4,
    DISPENSE_CHANGE = 5,
    EXIT = 6
};

class VendingMachineCore
{
    private:
        InputsManager       inputsManager_;
        CashManager         cashManager_;
        InventoryManager    inventoryManager_;
        bool                isProductSelected_;
        Product             selectedProduct_;
        State               state_;

    public:
        VendingMachineCore(/* args */);
        ~VendingMachineCore();

        uint32_t    boot();
        uint32_t    start();
        uint32_t    treatInput();
        uint32_t    checkStock();
        uint32_t    checkCash();
        uint32_t    dispenseProduct();
        uint32_t    dispenseChange();
        std::string refreshPrompt();
        void        setState(State state);
};
