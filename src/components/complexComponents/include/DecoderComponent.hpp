/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DecoderComponent
*/

#ifndef DECODERCOMPONENT_HPP_
#define DECODERCOMPONENT_HPP_

#include "AComponent.hpp"
#include <array>
#include <map>

namespace nts {
class DecoderComponent : public AComponent {
  public:
    DecoderComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
    void updateState() override;

  protected:
    std::array<Tristate, 16> allPins_;
    Tristate previousState_ { Undefined };
    std::map<std::size_t, std::size_t> indexMap_ { { 11, 0 }, { 9, 1 }, { 10, 2 }, { 8, 3 }, { 7, 4 }, { 6, 5 }, { 5, 6 }, { 4, 7 }, { 18, 8 }, { 17, 9 }, { 20, 10 }, { 19, 11 }, { 14, 12 }, { 13, 13 }, { 16, 14 }, { 15, 15 } };
};
}

#endif /* !DECODERCOMPONENT_HPP_ */
