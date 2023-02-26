/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourOrCreator
*/

#ifndef FOURORCREATOR_HPP_
#define FOURORCREATOR_HPP_
#include "FourOrComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class FourOrCreator : public ICreator {
  public:
    FourOrCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !FOURORCREATOR_HPP_ */
