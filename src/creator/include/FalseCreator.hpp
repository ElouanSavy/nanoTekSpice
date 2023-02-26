/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FalseCreator
*/

#ifndef FALSECREATOR_HPP_
#define FALSECREATOR_HPP_
#include "ICreator.hpp"
#include "FalseComponent.hpp"

namespace nts {
class FalseCreator : public ICreator {
  public:
    FalseCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !FALSECREATOR_HPP_ */
