/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** BitCounterComponent
*/

#include "BitCounterComponent.hpp"
#include <iostream>

nts::BitCounterComponent::BitCounterComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[9] = { 10, 11 };
    this->pinMap_[7] = { 10, 11 };
    this->pinMap_[6] = { 10, 11 };
    this->pinMap_[5] = { 10, 11 };
    this->pinMap_[3] = { 10, 11 };
    this->pinMap_[2] = { 10, 11 };
    this->pinMap_[4] = { 10, 11 };
    this->pinMap_[13] = { 10, 11 };
    this->pinMap_[12] = { 10, 11 };
    this->pinMap_[14] = { 10, 11 };
    this->pinMap_[15] = { 10, 11 };
    this->pinMap_[1] = { 10, 11 };
}

void nts::BitCounterComponent::incrementGate()
{
    int i = 0;
    int count = 0;
    for (i = 0; i < 12; i++) {
        if (allPins_[i] == True)
            count++;
    }
    if (count == 12) {
        for (i = 0; i < 12; i++) {
            allPins_[i] = False;
        }
        return;
    }
    for (i = 0; allPins_[i] == True; i++) {
        allPins_[i] = False;
    }
    allPins_[i] = True;
}

nts::Tristate nts::BitCounterComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return allPins_[this->indexMap_[pin]];
}

void nts::BitCounterComponent::updateState()
{
    std::list<int> inputList = this->pinMap_[12];
    std::vector<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }

    if (resultList[1] == True) {
        for (int i = 0; i < 12; i++) {
            allPins_[i] = False;
        }
    }

    if (resultList[0] == this->previousState_)
        return;
    this->previousState_ = resultList[0];

    if (resultList[0] == False) {
        this->incrementGate();
    }
}
