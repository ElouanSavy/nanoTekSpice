/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** ICreator
*/

#ifndef ICREATOR_HPP_
#define ICREATOR_HPP_
#include "IComponent.hpp"
#include <memory>

namespace nts {
class ICreator {
  public:
    virtual ~ICreator() = default;
    virtual std::unique_ptr<IComponent> createComponent(const std::string name) = 0;
};
}

#endif /* !ICREATOR_HPP_ */
