/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourNandCreator
*/

#ifndef FOURNANDCREATOR_HPP_
#define FOURNANDCREATOR_HPP_
#include "FourNandComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class FourNandCreator : public ICreator {
  public:
    FourNandCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}
#endif /* !FOURNANDCREATOR_HPP_ */
