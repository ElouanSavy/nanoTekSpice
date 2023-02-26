/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** OrComponent
*/

#include "OrComponent.hpp"
#include <vector>

nts::OrComponent::OrComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[3] = { 1, 2 };
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    std::list<int> inputList = this->pinMap_[pin];
    std::vector<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }

    return this->binaryOperator.or_(resultList[0], resultList[1]);
}
