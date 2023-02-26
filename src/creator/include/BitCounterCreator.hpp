/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** BitCounterComponent
*/

#ifndef BITCOUNTERCREATOR_HPP_
#define BITCOUNTERCREATOR_HPP_
#include "BitCounterComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class BitCounterCreator : public ICreator {
  public:
    BitCounterCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !BITCOUNTERCREATOR_HPP_ */
