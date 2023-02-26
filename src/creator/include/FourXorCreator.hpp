/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourXorCreator
*/

#ifndef FOURXORCREATOR_HPP_
#define FOURXORCREATOR_HPP_
#include "FourXorComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class FourXorCreator : public ICreator {
  public:
    FourXorCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !FOURXORCREATOR_HPP_ */
