/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourAndCreator
*/

#ifndef FOURANDCREATOR_HPP_
#define FOURANDCREATOR_HPP_
#include "FourAndComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class FourAndCreator : public ICreator {
  public:
    FourAndCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !FOURANDCREATOR_HPP_ */
