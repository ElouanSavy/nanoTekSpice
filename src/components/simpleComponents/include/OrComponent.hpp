/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "AComponent.hpp"
namespace nts {
class OrComponent : public AComponent {
  public:
    OrComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !ORCOMPONENT_HPP_ */
