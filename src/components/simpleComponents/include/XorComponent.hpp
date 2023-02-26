/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class XorComponent : public AComponent {
  public:
    XorComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !XORCOMPONENT_HPP_ */
