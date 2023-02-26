/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DecoderCreator
*/

#ifndef DECODERCREATOR_HPP_
#define DECODERCREATOR_HPP_
#include "DecoderComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class DecoderCreator : public ICreator {
  public:
    DecoderCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !DECODERCREATOR_HPP_ */
