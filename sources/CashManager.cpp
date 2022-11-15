/* CODE OF CASH MANAGER */

#include "CashManager.hpp"

CashManager::CashManager(/* args */):
    cash_(0.0),
    cashPaid_(0.0),
    nickelsPaid_(0),
    dimesPaid_(0),
    quartersPaid_(0),
    nickels_(0),
    dimes_(0),
    quarters_(0)
{
}

CashManager::~CashManager()
{
}

bool CashManager::canDispenseChange(double price) {
    uint32_t nickels = nickels_;
    uint32_t dimes = dimes_;
    uint32_t quarters = quarters_;
    // Check if money paid is enough to dispense change
    float difference = cashPaid_ - price;
    int integerDiff = static_cast<int>(difference * 100);
    // Check exact count of coins
    if (integerDiff == 0)
        return true;
    // Check if we have enough coins to dispense change
    while (integerDiff > 0) {
        if (integerDiff >= 25 && quarters > 0) {
            integerDiff -= 25;
            quarters--;
        } else if (integerDiff >= 10 && dimes > 0) {
            integerDiff -= 10;
            dimes--;
        } else if (integerDiff >= 5 && nickels > 0) {
            integerDiff -= 5;
            nickels--;
        } else {
            return false;
        }
    }
    return true;
}

void CashManager::dispenseChange(double price) {
    double difference = cashPaid_ - price;
    // Add paid coins to the machine
    quarters_ += quartersPaid_;
    dimes_ += dimesPaid_;
    nickels_ += nickelsPaid_;
    // Check exact count of coins
    if (difference == 0.0) {
        resetCashPaid();
        return;
    }
    // Reset paid coins as return coins
    quartersPaid_ = 0;
    dimesPaid_ = 0;
    nickelsPaid_ = 0;
    int integerDiff = static_cast<int>(difference * 100);
    // Dispense coins
    while (integerDiff > 0) {
        if (integerDiff >= 25 && quarters_ > 0) {
            difference -= 25;
            quarters_--;
            quartersPaid_++;
        } else if (integerDiff >= 10 && dimes_ > 0) {
            integerDiff -= 10;
            dimes_--;
            dimesPaid_++;
        } else if (integerDiff >= 5 && nickels_ > 0) {
            integerDiff -= 5;
            nickels_--;
            nickelsPaid_++;
        }
    }
}

void CashManager::resetCashPaid(void) {
    // Reset cash paid
    this->cashPaid_ = 0.0;
    this->nickelsPaid_ = 0;
    this->dimesPaid_ = 0;
    this->quartersPaid_ = 0;
}

// GETTERS
double CashManager::getCash() const
{
    return cash_;
}

double CashManager::getCashPaid() const
{
    return cashPaid_;
}

uint32_t CashManager::getPaidNickels() const
{
    return nickelsPaid_;
}

uint32_t CashManager::getPaidDimes() const
{
    return dimesPaid_;
}

uint32_t CashManager::getPaidQuarters() const
{
    return quartersPaid_;
}

uint32_t CashManager::getNickels() const
{
    return nickels_;
}

uint32_t CashManager::getDimes() const
{
    return dimes_;
}

uint32_t CashManager::getQuarters() const
{
    return quarters_;
}

// SETTERS

void CashManager::loadCash(void)
{
    // Load cash based on money in the machine
    // 1 nickel = 5 cents
    // 1 dime = 10 cents
    // 1 quarter = 25 cents
    cash_ = (nickels_ * 0.05) + (dimes_ * 0.10) + (quarters_ * 0.25);
}

void CashManager::setCashPaid(void)
{
    // Set cash paid based on money inserted by the user
    // 1 nickel = 5 cents
    // 1 dime = 10 cents
    // 1 quarter = 25 cents
    cashPaid_ = (nickelsPaid_ * 0.05) + (dimesPaid_ * 0.10) + (quartersPaid_ * 0.25);
}

void CashManager::setPaidNickels(uint32_t nickels)
{
    nickelsPaid_ = nickels;
    this->setCashPaid();
}

void CashManager::setPaidDimes(uint32_t dimes)
{
    dimesPaid_ = dimes;
    this->setCashPaid();
}

void CashManager::setPaidQuarters(uint32_t quarters)
{
    quartersPaid_ = quarters;
    this->setCashPaid();
}

void CashManager::setNickels(uint32_t nickels)
{
    nickels_ = nickels;
    this->loadCash();
}

void CashManager::setDimes(uint32_t dimes)
{
    dimes_ = dimes;
    this->loadCash();
}

void CashManager::setQuarters(uint32_t quarters)
{
    quarters_ = quarters;
    this->loadCash();
}