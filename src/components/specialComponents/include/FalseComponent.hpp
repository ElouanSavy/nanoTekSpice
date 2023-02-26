/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class FalseComponent : public AComponent {
  public:
    FalseComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !FALSECOMPONENT_HPP_ */
