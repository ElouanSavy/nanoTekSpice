/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class OutputComponent : public AComponent {
  public:
    OutputComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
