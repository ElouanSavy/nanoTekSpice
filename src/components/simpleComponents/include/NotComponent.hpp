/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** FalseComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class NotComponent : public AComponent {
  public:
    NotComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !NOTCOMPONENT_HPP_ */
