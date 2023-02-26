/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class AndComponent : public AComponent {
  public:
    AndComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !ANDCOMPONENT_HPP_ */
