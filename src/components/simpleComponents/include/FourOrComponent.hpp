/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourOrComponent
*/

#ifndef FOURORCOMPONENT_HPP_
#define FOURORCOMPONENT_HPP_

#include "AComponent.hpp"
namespace nts {
class FourOrComponent : public AComponent {
  public:
    FourOrComponent(std::string name= "");
    Tristate compute(std::size_t pin) override;
};
}
#endif /* !FOURORCOMPONENT_HPP_ */
