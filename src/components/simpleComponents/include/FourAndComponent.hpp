/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourAndComponent
*/

#ifndef FOURANDCOMPONENT_HPP_
#define FOURANDCOMPONENT_HPP_

#include "AComponent.hpp"
namespace nts {
class FourAndComponent : public AComponent {
  public:
    FourAndComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !FOURANDCOMPONENT_HPP_ */
