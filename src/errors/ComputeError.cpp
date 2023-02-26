/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** ComputeError
*/

#include "Errors.hpp"

nts::ComputeError::ComputeError(const char* type)
    : type(type)
{
}

const char* nts::ComputeError::what() const noexcept
{
    return this->type;
}
