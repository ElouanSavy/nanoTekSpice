/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourAndComponent
*/

#include "FourAndComponent.hpp"
#include <vector>

nts::FourAndComponent::FourAndComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[3] = { 1, 2 };
    this->pinMap_[4] = { 5, 6 };
    this->pinMap_[10] = { 8, 9 };
    this->pinMap_[11] = { 12, 13 };
}

nts::Tristate nts::FourAndComponent::compute(std::size_t pin)
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
