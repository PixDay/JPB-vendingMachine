/* INCLUDE OF CASH MANAGER */

#pragma once

#include <cstdint>

class CashManager
{
    private:
        double cash_;
        double cashPaid_;
        uint32_t  nickelsPaid_;
        uint32_t dimesPaid_;
        uint32_t quartersPaid_;
        uint32_t nickels_;
        uint32_t dimes_;
        uint32_t quarters_;

    public:
        CashManager(/* args */);
        ~CashManager();

        bool canDispenseChange(double price);
        void dispenseChange(double price);
        void resetCashPaid(void);

        // GETTERS
        double getCash() const;
        double getCashPaid() const;
        uint32_t getPaidNickels() const;
        uint32_t getPaidDimes() const;
        uint32_t getPaidQuarters() const;
        uint32_t getNickels() const;
        uint32_t getDimes() const;
        uint32_t getQuarters() const;

        // SETTERS
        void loadCash(void);
        void setCashPaid(void);
        void setPaidNickels(uint32_t nickels);
        void setPaidDimes(uint32_t dimes);
        void setPaidQuarters(uint32_t quarters);
        void setNickels(uint32_t nickels);
        void setDimes(uint32_t dimes);
        void setQuarters(uint32_t quarters);
};