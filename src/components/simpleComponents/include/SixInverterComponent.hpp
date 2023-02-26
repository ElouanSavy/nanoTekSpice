/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** SixInverter
*/

#ifndef SIXINVERTERCOMPONENT_HPP_
#define SIXINVERTERCOMPONENT_HPP_
#include "AComponent.hpp"

namespace nts {
class SixInverterComponent : public AComponent {
  public:
    SixInverterComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    Tristate computeInvert(Tristate a);
};
}

#endif /* !SIXINVERTERCOMPONENT_HPP_ */
