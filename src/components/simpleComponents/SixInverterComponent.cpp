/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** SixInverter
*/

#include "SixInverterComponent.hpp"

nts::SixInverterComponent::SixInverterComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[2] = { 1 };
    this->pinMap_[4] = { 3 };
    this->pinMap_[6] = { 5 };
    this->pinMap_[8] = { 9 };
    this->pinMap_[10] = { 11 };
    this->pinMap_[12] = { 13 };
}

nts::Tristate nts::SixInverterComponent::computeInvert(Tristate a)
{
    if (a == Undefined)
        return Undefined;

    return a == False ? True : False;
}

nts::Tristate nts::SixInverterComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    std::list<int> inputList = this->pinMap_[pin];
    std::vector<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }

    return this->computeInvert(resultList.front());
}
