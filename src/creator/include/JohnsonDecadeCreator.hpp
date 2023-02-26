/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** JohnsonDecadeCreator
*/

#ifndef JOHNSONDECADECREATOR_HPP_
#define JOHNSONDECADECREATOR_HPP_
#include "JohnsonDecadeComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class JohnsonDecadeCreator : public ICreator {
  public:
    JohnsonDecadeCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}
#endif /* !JOHNSONDECADECREATOR_HPP_ */
