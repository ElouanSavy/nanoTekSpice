/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(std::string name)
{
    this->name_ = name;
    this->type_ = OUTPUT;
    this->pinMap_[0] = { 1 };
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return this->getLink(1);
}
