/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** AndCreator
*/

#include "AndCreator.hpp"

std::unique_ptr<nts::IComponent> nts::AndCreator::createComponent(const std::string name)
{
    return std::move(std::make_unique<nts::AndComponent>(name));
}

