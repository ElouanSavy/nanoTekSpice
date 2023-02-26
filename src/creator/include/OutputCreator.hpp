/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** OutputCreator
*/

#ifndef OUTPUTCREATOR_HPP_
#define OUTPUTCREATOR_HPP_
#include "ICreator.hpp"
#include "OutputComponent.hpp"

namespace nts {
class OutputCreator : public ICreator {
  public:
    OutputCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}
#endif /* !OUTPUTCREATOR_HPP_ */
