/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** NotCreator
*/

#ifndef NOTCREATOR_HPP_
#define NOTCREATOR_HPP_
#include "NotComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class NotCreator : public ICreator {
  public:
    NotCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !NOTCREATOR_HPP_ */
