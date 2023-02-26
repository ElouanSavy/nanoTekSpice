/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** XorCreator
*/

#ifndef XORCREATOR_HPP_
#define XORCREATOR_HPP_
#include "XorComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class XorCreator : public ICreator {
  public:
    XorCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !XORCREATOR_HPP_ */
