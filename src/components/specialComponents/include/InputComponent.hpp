/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class InputComponent : public AComponent {
  public:
    InputComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    void setActualState(Tristate state) override;

  private:
    Tristate actualState_ { Undefined };
};
}

#endif /* !INPUTCOMPONENT_HPP_ */
