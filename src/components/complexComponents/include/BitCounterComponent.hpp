/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** BitCounterComponent
*/

#ifndef BITCOUNTERCOMPONENT_HPP_
#define BITCOUNTERCOMPONENT_HPP_

#include "AComponent.hpp"
#include <array>
#include <map>

namespace nts {
class BitCounterComponent : public AComponent {
  public:
    BitCounterComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    void updateState() override;
    void incrementGate();

  private:
    std::array<Tristate, 12> allPins_ { False };
    std::map<std::size_t, std::size_t> indexMap_ { { 9, 0 }, { 7, 1 }, { 6, 2 }, { 5, 3 }, { 3, 4 }, { 2, 5 }, { 4, 6 }, { 13, 7 }, { 12, 8 }, { 14, 9 }, { 15, 10 }, { 1, 11 } };
    Tristate previousState_ { Undefined };
};
}

#endif /* !BITCOUNTERCOMPONENT_HPP_ */
