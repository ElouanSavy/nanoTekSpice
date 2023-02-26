/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** ParsingErrors
*/

#include "Errors.hpp"

nts::ParsingError::ParsingError(const char* type)
    : type(type)
{
}

const char* nts::ParsingError::what() const noexcept
{
    return this->type;
}
