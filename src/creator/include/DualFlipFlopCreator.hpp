/*
** EPITECH PROJECT, 2023
** $
** File description:
** DualFlipFlopCreator
*/

#ifndef DUALFLIPFLOPCREATOR_HPP_
#define DUALFLIPFLOPCREATOR_HPP_
#include "DualFlipFlopComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class DualFlipFlopCreator : public ICreator {
  public:
    DualFlipFlopCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !DUALFLIPFLOPCREATOR_HPP_ */
