/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** OrCreator
*/

#ifndef ORCREATOR_HPP_
#define ORCREATOR_HPP_
#include "ICreator.hpp"
#include "OrComponent.hpp"

namespace nts {
class OrCreator : public ICreator {
  public:
    OrCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !ORCREATOR_HPP_ */
