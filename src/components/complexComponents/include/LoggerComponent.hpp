/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
#define LOGGERCOMPONENT_HPP_
#include "AComponent.hpp"
#include <fstream>
#include <cstring>
#include <bitset>
#include <cmath>
#include <sstream>

namespace nts {
class LoggerComponent : public AComponent {
  public:
    LoggerComponent(std::string name);
    Tristate compute(std::size_t pin) override;
    void updateState() override;

  private:
    Tristate previousState_ { Undefined };
};
}

#endif /* !LOGGERCOMPONENT_HPP_ */
