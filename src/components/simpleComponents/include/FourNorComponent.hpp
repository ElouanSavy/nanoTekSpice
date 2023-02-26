/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourNorComponent
*/

#ifndef FOURNORCOMPONENT_HPP_
#define FOURNORCOMPONENT_HPP_

#include "AComponent.hpp"
namespace nts {
class FourNorComponent : public AComponent {
  public:
    FourNorComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}
#endif /* !FOURNORCOMPONENT_HPP_ */
