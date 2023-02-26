/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DualFlipFlopComponent
*/

#ifndef DUALFLIPFLOPCOMPONENT_HPP_
#define DUALFLIPFLOPCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
class DualFlipFlopComponent : public AComponent {
  public:
    DualFlipFlopComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    Tristate getSavedValue(std::size_t pin);
    void setSavedValue(std::size_t pin, nts::Tristate result);
    void setSameSavedValue(std::size_t pin, nts::Tristate result);
    Tristate getFlipFlopValue(std::size_t pin, Tristate clock, Tristate reset, Tristate data, Tristate set);
  private:
    std::vector<Tristate> savedPins_{Undefined, Undefined, Undefined, Undefined};
};
}

#endif /* !DUALFLIPFLOPCOMPONENT_HPP_ */
