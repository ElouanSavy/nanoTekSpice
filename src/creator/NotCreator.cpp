/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** NotCreator
*/

#include "NotCreator.hpp"

std::unique_ptr<nts::IComponent> nts::NotCreator::createComponent(const std::string name)
{
    return std::move(std::make_unique<nts::NotComponent>(name));
}

