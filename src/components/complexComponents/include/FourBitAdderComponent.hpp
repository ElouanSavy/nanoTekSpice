/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourBitAdderComponent
*/

#ifndef FOURBITADDER_HPP_
#define FOURBITADDER_HPP_
#include "AComponent.hpp"

namespace nts {
class FourBitAdderComponent : public AComponent {
  public:
    FourBitAdderComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    Tristate computeCout(Tristate a, Tristate b, Tristate c);
    Tristate computeSout(Tristate a, Tristate b, Tristate c);
    void updateState() override;
    Tristate getCout();

  private:
    std::map<std::size_t, nts::Tristate> output_ { { 10, Undefined }, { 11, Undefined }, { 12, Undefined }, { 13, Undefined }, { 14, Undefined } };
};
}

#endif /* !FOURBITADDER_HPP_ */
