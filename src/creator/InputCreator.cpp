/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** InputCreator
*/

#include "InputCreator.hpp"
#include "InputComponent.hpp"

std::unique_ptr<nts::IComponent> nts::InputCreator::createComponent(const std::string name)
{
    return std::move(std::make_unique<nts::InputComponent>(name));
}
