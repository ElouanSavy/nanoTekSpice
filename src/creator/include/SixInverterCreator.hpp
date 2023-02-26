/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** SixInverterCreator
*/

#ifndef SIXINVERTERCREATOR_HPP_
#define SIXINVERTERCREATOR_HPP_
#include "ICreator.hpp"
#include "SixInverterComponent.hpp"

namespace nts {
class SixInverterCreator : public ICreator {
  public:
    SixInverterCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !SIXINVERTERCREATOR_HPP_ */
