/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourNandComponent
*/

#ifndef FOURNANDCOMPONENT_HPP_
#define FOURNANDCOMPONENT_HPP_

#include "AComponent.hpp"
namespace nts {
class FourNandComponent : public AComponent {
  public:
    FourNandComponent(std::string name = "");
    Tristate compute(std::size_t pin) override;
};
}
#endif /* !FOURNANDCOMPONENT_HPP_ */
