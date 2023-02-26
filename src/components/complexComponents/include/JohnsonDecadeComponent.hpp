/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** JohnsonDecadeComponent
*/

#ifndef JOHNSONDECADECOMPONENT_HPP_
#define JOHNSONDECADECOMPONENT_HPP_
#include "AComponent.hpp"
#include <array>

namespace nts {
class JohnsonDecadeComponent : public AComponent {
  public:
    JohnsonDecadeComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    void resetGate();
    void computeClock();
    void updateState() override;

  private:
    std::size_t savePin_ = 0;
    Tristate previousState_ {Undefined};
    std::array<Tristate, 10> allPins_ { False };
    std::map<std::size_t, std::size_t> indexMap_ { { 3, 0 }, { 2, 1 }, { 4, 2 }, { 7, 3 }, { 10, 4 }, { 1, 5 }, { 5, 6 }, { 6, 7 }, { 9, 8 }, { 11, 9 } };
};
}

#endif /* !JOHNSONDECADECOMPONENT_HPP_ */
