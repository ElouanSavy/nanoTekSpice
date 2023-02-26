/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourNandCreator
*/

#include "FourNandCreator.hpp"

std::unique_ptr<nts::IComponent> nts::FourNandCreator::createComponent(const std::string name)
{
    return std::move(std::make_unique<nts::FourNandComponent>(name));
}
