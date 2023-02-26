/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** AndComponent
*/

#include "AndComponent.hpp"
#include <vector>

nts::AndComponent::AndComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[3] = { 1, 2 };
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    std::list<int> inputList = this->pinMap_[pin];
    std::vector<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }

    return this->binaryOperator.and_(resultList[0], resultList[1]);
}
