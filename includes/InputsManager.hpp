/* INCLUDE OF INPUTS MANAGER */

#pragma once

#include <iostream>
#include <cstdint>
#include <string>

class InputsManager
{
    private:
        std::string input_;

    public:
        InputsManager(/* args */);
        ~InputsManager();

        // GETTERS
        std::string getInput(std::string promptInfos);
        std::string getInput(void);
};