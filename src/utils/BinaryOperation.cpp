/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** BinaryOperation
*/

#include "AComponent.hpp"

nts::Tristate nts::BinaryOperation::and_(nts::Tristate a, nts::Tristate b)
{
    if (a == False || b == False)
        return False;
    if (a == True && b == Undefined)
        return Undefined;
    if (b == True && a == Undefined)
        return Undefined;
    if (a == Undefined && b == Undefined)
        return Undefined;
    return True;
}

nts::Tristate nts::BinaryOperation::nand_(nts::Tristate a, nts::Tristate b)
{
    if (a == False || b == False)
        return True;
    if (a == True && b == Undefined)
        return Undefined;
    if (b == True && a == Undefined)
        return Undefined;
    if (a == Undefined && b == Undefined)
        return Undefined;
    return False;
}

nts::Tristate nts::BinaryOperation::nor_(nts::Tristate a, nts::Tristate b)
{
    if (a == True || b == True)
        return False;
    if (a == False && b == Undefined)
        return Undefined;
    if (b == False && a == Undefined)
        return Undefined;
    if (a == Undefined && b == Undefined)
        return Undefined;
    return True;
}

nts::Tristate nts::BinaryOperation::or_(nts::Tristate a, nts::Tristate b)
{
    if (a == True || b == True)
        return True;
    if (a == False && b == Undefined)
        return Undefined;
    if (b == False && a == Undefined)
        return Undefined;
    if (a == Undefined && b == Undefined)
        return Undefined;
    return False;
}

nts::Tristate nts::BinaryOperation::xor_(nts::Tristate a, nts::Tristate b)
{
    if (a == Undefined || b == Undefined)
        return Undefined;
    if (a == False && b == False)
        return False;
    if (a == True && b == True)
        return False;
    return True;
}
