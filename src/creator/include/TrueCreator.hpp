/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TrueCreator
*/

#ifndef TRUECREATOR_HPP_
#define TRUECREATOR_HPP_
#include "ICreator.hpp"
#include "TrueComponent.hpp"

namespace nts {
class TrueCreator : public ICreator {
  public:
    TrueCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !TRUECREATOR_HPP_ */
