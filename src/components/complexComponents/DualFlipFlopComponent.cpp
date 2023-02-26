/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DualFlipFlopComponent
*/

#include "DualFlipFlopComponent.hpp"

nts::DualFlipFlopComponent::DualFlipFlopComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[1] = { 3, 4, 5, 6 }; // [0] = Clock - [1] = Reset - [2] = Data - [3] = Set
    this->pinMap_[2] = { 3, 4, 5, 6 };
    this->pinMap_[12] = { 11, 10, 9, 8 };
    this->pinMap_[13] = { 11, 10, 9, 8 };
}

nts::Tristate nts::DualFlipFlopComponent::getSavedValue(std::size_t pin)
{
    if (pin == 1)
        return this->savedPins_[0];
    else if (pin == 2)
        return this->savedPins_[1];
    else if (pin == 13)
        return this->savedPins_[2];
    return this->savedPins_[3];
}

void nts::DualFlipFlopComponent::setSavedValue(std::size_t pin, nts::Tristate result)
{
    if (pin == 1 || pin == 2) {
        this->savedPins_[0] = result;
        this->savedPins_[1] = !result;
    }
    if (pin == 13 || pin == 12) {
        this->savedPins_[2] = result;
        this->savedPins_[3] = !result;
    }
}

void nts::DualFlipFlopComponent::setSameSavedValue(std::size_t pin, nts::Tristate result)
{
    if (pin == 1 || pin == 2) {
        this->savedPins_[0] = result;
        this->savedPins_[1] = result;
    }
    if (pin == 13 || pin == 12) {
        this->savedPins_[2] = result;
        this->savedPins_[3] = result;
    }
}

nts::Tristate nts::DualFlipFlopComponent::getFlipFlopValue(std::size_t pin, Tristate clock, Tristate reset, Tristate data, Tristate set)
{
    nts::Tristate result = Undefined;

    if (clock == True && reset == False && data == False && set == False)
        result = False;
    if (clock == True && reset == False && data == True && set == False)
        result = True;
    if (clock == False && reset == False && set == False)
        return getSavedValue(pin);
    if (reset == True && set == False)
        result = False;
    if (reset == True && set == True) {
        this->setSameSavedValue(pin, set);
        return set;
    }
    if (reset == False && set == True)
        result = True;
    this->setSavedValue(pin, result);
    if (pin == 2 || pin == 12)
        return !result;
    return result;
}

nts::Tristate nts::DualFlipFlopComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    std::list<int> inputList = this->pinMap_[pin];
    std::vector<Tristate> resultList;
    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }
    return this->getFlipFlopValue(pin, resultList[0], resultList[1], resultList[2], resultList[3]);
}
