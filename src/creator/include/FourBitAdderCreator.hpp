/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** FourBitAdderCreator
*/

#ifndef FOURBITADDERCREATOR_HPP_
#define FOURBITADDERCREATOR_HPP_
#include "FourBitAdderComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class FourBitAdderCreator : public ICreator {
  public:
    FourBitAdderCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !FOURBITADDERCREATOR_HPP_ */
