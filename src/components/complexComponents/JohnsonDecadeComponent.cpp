/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** JohnsonDecadeComponent
*/

#include "JohnsonDecadeComponent.hpp"

nts::JohnsonDecadeComponent::JohnsonDecadeComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[12] = { 15, 13, 14 };
    this->pinMap_[11] = { 15, 13, 14 };
    this->pinMap_[10] = { 15, 13, 14 };
    this->pinMap_[9] = { 15, 13, 14 };
    this->pinMap_[7] = { 15, 13, 14 };
    this->pinMap_[6] = { 15, 13, 14 };
    this->pinMap_[5] = { 15, 13, 14 };
    this->pinMap_[4] = { 15, 13, 14 };
    this->pinMap_[3] = { 15, 13, 14 };
    this->pinMap_[2] = { 15, 13, 14 };
    this->pinMap_[1] = { 15, 13, 14 };
    this->allPins_[0] = True;
}

void nts::JohnsonDecadeComponent::computeClock()
{
    this->allPins_[this->savePin_] = False;
    this->savePin_ + 1 > 9 ? this->savePin_ = 0 : this->savePin_ += 1;
    this->allPins_[this->savePin_] = True;
}

void nts::JohnsonDecadeComponent::resetGate()
{
    this->allPins_[this->savePin_] = False;
    this->savePin_ = 0;
    this->allPins_[0] = True;
}

nts::Tristate nts::JohnsonDecadeComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    if (pin == 12) {
        return (this->savePin_ < 5 ? True : False);
    }

    return allPins_[this->indexMap_[pin]];
}

void nts::JohnsonDecadeComponent::updateState()
{
    std::list<int> inputList = this->pinMap_[12];
    std::vector<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }

    if (resultList[0] == True) {
        this->resetGate();
        return;
    }

    if (resultList[2] == this->previousState_)
        return;
    this->previousState_ = resultList[2];

    if (resultList[1] == True)
        return;
    if (resultList[2] == True)
        this->computeClock();
}
