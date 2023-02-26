/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[2] = { 1 };
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    std::list<int> inputList = this->pinMap_[pin];
    std::list<Tristate> resultList;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }

    if (resultList.front() == Undefined)
        return Undefined;

    return resultList.front() == False ? True : False;
}
