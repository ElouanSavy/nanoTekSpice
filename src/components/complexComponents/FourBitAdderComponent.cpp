/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourBitAdderComponent
*/

#include "FourBitAdderComponent.hpp"

nts::FourBitAdderComponent::FourBitAdderComponent(std::string name)
{
    this->name_ = name;
    this->pinMap_[14] = { 1, 2, 3, 4, 5, 6, 7, 9, 15 };
    this->pinMap_[13] = { 1, 15, 9 };
    this->pinMap_[12] = { 2, 3, 9 };
    this->pinMap_[11] = { 4, 5, 9 };
    this->pinMap_[10] = { 6, 7, 9 };
}

nts::Tristate nts::FourBitAdderComponent::computeCout(Tristate a, Tristate b, Tristate c)
{
    return (Tristate)(a * b + (c * binaryOperator.xor_(a, b)));
}

nts::Tristate nts::FourBitAdderComponent::computeSout(Tristate a, Tristate b, Tristate c)
{
    return (binaryOperator.xor_(binaryOperator.xor_(a, b), c));
}

nts::Tristate nts::FourBitAdderComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return this->output_[pin];
}

void nts::FourBitAdderComponent::updateState()
{
    Tristate cout = this->getLink(9);
    int mapIndex = 10;
    Tristate link1 = Undefined;
    Tristate link2 = Undefined;

    for (int i = 7; i > 1; i -= 2) {
        link1 = this->getLink(i - 1);
        link2 = this->getLink(i);
        this->output_[mapIndex++] = this->computeSout(link2, link1, cout);
        cout = this->computeCout(link1, link2, cout);
    }
    link1 = this->getLink(15);
    link2 = this->getLink(1);
    this->output_[mapIndex++] = this->computeSout(link2, link1, cout);
    this->output_[14] = this->computeCout(link1, link2, cout);
}
