/* CODE OF MACHINE VENDING CORE */

#include "VendingMachineCore.hpp"

VendingMachineCore::VendingMachineCore(/* args */):
    isProductSelected_(false),
    selectedProduct_()
{
}

VendingMachineCore::~VendingMachineCore()
{
}

uint32_t VendingMachineCore::boot()
{
    std::cout << "Vending Machine Core is booting..." << std::endl;
    this->state_ = INITIAL_STATE;

    std::cout << "Initializating inventory..." << std::endl;
    this->inventoryManager_.addProduct(Product(0, 1.0f, "Cola"), 2);
    this->inventoryManager_.addProduct(Product(1, 0.50f, "Chips"), 2);
    this->inventoryManager_.addProduct(Product(2, 0.65f, "Candy"), 2);

    std::cout << "Initializating cash..." << std::endl;
    this->cashManager_.setDimes(30);
    this->cashManager_.setNickels(30);
    this->cashManager_.setQuarters(30);
    this->cashManager_.loadCash();

    std::cout << "Initializating inputs..." << std::endl;
    std::cout << "Vending Machire Core is ready to start\n" << std::endl;
    this->inventoryManager_.showProducts();
    std::cout << "\n" << std::endl;
    return 0;
}

uint32_t VendingMachineCore::start()
{
    // Loop until user wants to exit
    while(state_ != EXIT) {
        inputsManager_.getInput(refreshPrompt());
        treatInput();
        if (state_ == CHECK_STOCK) {
            checkStock();
        }
        if (state_ == CHECK_CASH) {
            checkCash();
        }
        if (state_ == DISPENSE_CHANGE) {
            dispenseChange();
        }
        if (state_ == DISPENSE_PRODUCT) {
            dispenseProduct();
        }
    }
    return 0;
}

std::string VendingMachineCore::refreshPrompt() {
    if(isProductSelected_) {
        return "Please insert " + std::to_string(selectedProduct_.getPrice()) + "$ for the (" + selectedProduct_.getName() + ") or select another product (" + std::to_string(this->cashManager_.getCashPaid()) + "$): ";
    }
    return "Please select a product: (" + std::to_string(this->cashManager_.getCashPaid()) + "$): ";
}

bool is_number(const std::string& s)
{
    return( strspn( s.c_str(), ".0123456789" ) == s.size() );
}

uint32_t VendingMachineCore::treatInput()
{
    // Check if input from the InputsManager is a number
    if (is_number(inputsManager_.getInput())) {
        // Transform input from string to float
        float coin = std::stof(inputsManager_.getInput());
        // Check if input is a coin
        if (coin == 0.05f || coin == 0.10f || coin == 0.25f) {
            // Add coin to the cash manager
            if (coin == 0.05f) {
                this->cashManager_.setPaidNickels(this->cashManager_.getPaidNickels() + 1);
            }
            if (coin == 0.10f) {
                this->cashManager_.setPaidDimes(this->cashManager_.getPaidDimes() + 1);
            }
            if (coin == 0.25f) {
                this->cashManager_.setPaidQuarters(this->cashManager_.getPaidQuarters() + 1);
            }
            // Set state to check cash
            this->setState(CHECK_CASH);
        } else {
            std::cout << "Invalid input ! the number you entered is not a valid coin" << std::endl;
        }
    } else {
        // Check if input is a product contained in the inventory
        if (this->inventoryManager_.getProduct(inputsManager_.getInput()) != Product()) {
            this->selectedProduct_ = this->inventoryManager_.getProduct(inputsManager_.getInput());
            this->isProductSelected_ = true;
            this->setState(CHECK_STOCK);
        } else {
            std::cout << "Invalid input ! the product you entered is not in the inventory" << std::endl;
            this->isProductSelected_ = false;
            this->setState(INITIAL_STATE);
        }
    }
    return 0;
}

uint32_t VendingMachineCore::checkStock()
{
    // Check if the product is in stock
    if (this->inventoryManager_.getQuantityOf(this->selectedProduct_.getId()) > 0) {
        // Set state to check cash
        this->setState(CHECK_CASH);
    } else {
        std::cout << "The product you selected is not in stock" << std::endl;
        this->isProductSelected_ = false;
        this->setState(INITIAL_STATE);
    }
    return 0;
}

uint32_t VendingMachineCore::checkCash()
{
    // Check if a product is selected
    if (!isProductSelected_)
        return 0;
    // Check if the cash paid is enough
    if (this->cashManager_.getCashPaid() >= this->selectedProduct_.getPrice()) {
        // Set state to dispense product
        this->setState(DISPENSE_CHANGE);
    }
    return 0;
}

uint32_t VendingMachineCore::dispenseProduct()
{
    // Dispense product
    this->inventoryManager_.removeProduct(this->selectedProduct_.getId());
    std::cout << "Here is your product: (" << this->selectedProduct_.getName() << ")" << std::endl;
    std::cout << "Here is your money: " << this->cashManager_.getPaidDimes() << " dimes, " << this->cashManager_.getPaidNickels() << " nickels, " << this->cashManager_.getPaidQuarters() << " quarters" << std::endl;
    std::cout << "Thank you for your purchase !\n" << std::endl;
    this->cashManager_.resetCashPaid();
    this->inventoryManager_.showProducts();
    // Set state to dispense change
    this->setState(INITIAL_STATE);
    this->isProductSelected_ = false;
    return 0;
}

uint32_t VendingMachineCore::dispenseChange()
{
    // Dispense change
    if (cashManager_.canDispenseChange(selectedProduct_.getPrice())) {
        cashManager_.dispenseChange(selectedProduct_.getPrice());
        this->setState(DISPENSE_PRODUCT);
    } else {
        std::cout << "Sorry, we can't dispense change (money is sent back)" << std::endl;
        this->cashManager_.resetCashPaid();
        this->setState(INITIAL_STATE);
        this->isProductSelected_ = false;
    }
    return 0;
}

void VendingMachineCore::setState(State state)
{
    state_ = state;
}