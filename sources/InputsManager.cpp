/* CODE OF INPUTS MANAGER */

#include "InputsManager.hpp"

InputsManager::InputsManager():
    input_("")
{
}

InputsManager::~InputsManager()
{
}


// GETTERS
std::string InputsManager::getInput(std::string promptInfos) {
    // Prompt user to enter input
    std::cout << promptInfos;
    // Get input from user terminal
    std::cin >> this->input_;

    // Lowercase input
    for (auto &c : this->input_) {
        c = tolower(c);
    }

    return this->input_;
}

std::string InputsManager::getInput(void) {
    return this->input_;
}