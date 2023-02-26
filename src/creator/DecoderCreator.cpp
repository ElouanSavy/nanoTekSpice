/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DecoderCreator
*/

#include "DecoderCreator.hpp"

std::unique_ptr<nts::IComponent> nts::DecoderCreator::createComponent(const std::string name)
{
    return std::move(std::make_unique<nts::DecoderComponent>(name));
}
