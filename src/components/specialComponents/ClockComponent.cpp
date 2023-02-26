/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(std::string name)
{
    this->name_ = name;
    this->type_ = INPUT;
    this->pinMap_[1] = {};
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return this->actualState_;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
    this->actualState_ = !this->actualState_;
}

void nts::ClockComponent::setActualState(Tristate state)
{
    this->actualState_ = state;
}
