/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** LoggerCreator
*/

#ifndef LOGGERCREATOR_HPP_
#define LOGGERCREATOR_HPP_
#include "LoggerComponent.hpp"
#include "ICreator.hpp"

namespace nts {
class LoggerCreator : public ICreator {
  public:
    LoggerCreator() = default;
    std::unique_ptr<IComponent> createComponent(const std::string name) final;
};
}

#endif /* !LOGGERCREATOR_HPP_ */
