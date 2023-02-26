/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** AndCreator
*/

#ifndef ANDCREATOR_HPP_
#define ANDCREATOR_HPP_
#include "AndComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class AndCreator : public ICreator {
  public:
    AndCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !ANDCREATOR_HPP_ */
