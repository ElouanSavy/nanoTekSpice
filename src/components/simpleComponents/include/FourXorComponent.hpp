/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourXorComponent
*/

#ifndef FOURXORCOMPONENT_HPP_
#define FOURXORCOMPONENT_HPP_
#include "AComponent.hpp"
namespace nts {
class FourXorComponent : public AComponent {
  public:
    FourXorComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}

#endif /* !FOURXORCOMPONENT_HPP_ */
