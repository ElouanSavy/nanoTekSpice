/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
class ClockComponent : public AComponent {
  public:
    ClockComponent(std::string name = "");
    void simulate(std::size_t tick) override;
    Tristate compute(std::size_t pin) override;
    void setActualState(Tristate state) override;
    // Tristate getActualState() const;
    Tristate actualState_ { Undefined };
};
}

#endif /* !CLOCKCOMPONENT_HPP_ */
