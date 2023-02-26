/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** InputCreator
*/

#ifndef INPUTCREATOR_HPP_
#define INPUTCREATOR_HPP_

#include "ICreator.hpp"
namespace nts {
class InputCreator : public ICreator {
    public:
        InputCreator() = default;
        std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !INPUTCREATOR_HPP_ */
