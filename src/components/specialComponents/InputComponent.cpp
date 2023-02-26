/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent(std::string name)
{
    this->name_ = name;
    this->type_ = INPUT;
    this->pinMap_[1] = {};
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return this->actualState_;
}

void nts::InputComponent::setActualState(Tristate state)
{
    this->actualState_ = state;
}
