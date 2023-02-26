/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

nts::FalseComponent::FalseComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[1] = {};
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return False;
}
