/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** ClockCreator
*/

#ifndef CLOCKCREATOR_HPP_
#define CLOCKCREATOR_HPP_
#include "ICreator.hpp"
#include "ClockComponent.hpp"

namespace nts {
class ClockCreator : public ICreator {
  public:
    ClockCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}
#endif /* !CLOCKCREATOR_HPP_ */
