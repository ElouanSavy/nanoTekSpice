/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourNorCreator
*/

#ifndef FOURNORCREATOR_HPP_
#define FOURNORCREATOR_HPP_
#include "FourNorComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class FourNorCreator : public ICreator {
  public:
    FourNorCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}
#endif /* !FOURNORCREATOR_HPP_ */
