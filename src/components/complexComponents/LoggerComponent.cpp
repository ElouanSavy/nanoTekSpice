/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** LoggerComponent
*/

#include "LoggerComponent.hpp"

nts::LoggerComponent::LoggerComponent(std::string name)
{
    this->pinMap_[0] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    this->name_ = name;
}

nts::Tristate nts::LoggerComponent::compute(std::size_t pin)
{
    (void)pin;
    return Undefined;
}

void nts::LoggerComponent::updateState()
{
    Tristate state = this->getLink(9);
    std::vector<int> states;
    int tmp = 0;
    std::string tmpChar = "";
    if (state == this->previousState_)
        return;
    this->previousState_ = state;

    if (this->previousState_ != True || this->getLink(10) == True)
        return;
    for (int i = 1; i < 9; i++) {
        Tristate tmp = this->getLink(i);
        if (tmp == Undefined) {
            return;
        }
        states.push_back(tmp);
    }
    for (std::size_t i = 0; i < states.size(); i++) {
        if (states[i])
            tmp += pow(states[i] * 2, i);
    }
    std::fstream fs { "./log.bin", fs.app | fs.out };
    if (!fs.is_open())
        throw ComputeError(strerror(errno));
    fs.put(tmp);
    fs.close();
}
