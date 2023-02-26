/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[3] = { 1, 2 };
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    std::list<int> inputList = this->pinMap_[pin];
    std::vector<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }
    return this->binaryOperator.xor_(resultList[0], resultList[1]);
}
