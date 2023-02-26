/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** MappingError
*/

#include "Errors.hpp"

nts::MappingError::MappingError(const char* type)
    : type(type)
{
}

const char* nts::MappingError::what() const noexcept
{
    return this->type;
}
