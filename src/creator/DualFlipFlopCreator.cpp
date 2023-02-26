/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DualFlipFlopCreator
*/

#include "DualFlipFlopCreator.hpp"

std::unique_ptr<nts::IComponent> nts::DualFlipFlopCreator::createComponent(const std::string name)
{
    return std::move(std::make_unique<nts::DualFlipFlopComponent>(name));
}
