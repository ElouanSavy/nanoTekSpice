/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** FalseComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class TrueComponent : public AComponent {
  public:
    TrueComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !TRUECOMPONENT_HPP_ */
