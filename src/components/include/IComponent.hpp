/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include <iostream>
#include <list>
#include <map>
#include <vector>

namespace nts {
enum Tristate { Undefined = (-true),
    True = true,
    False = false };

enum ComponentType { INPUT,
    OUTPUT,
    OTHER };

class IComponent {
  public:
    virtual ~IComponent() = default;
    virtual void simulate(std::size_t tick) = 0;
    virtual nts::Tristate compute(std::size_t pin) = 0;
    virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
    virtual void setActualState(nts::Tristate state) = 0;
    virtual std::string getName() const = 0;
    virtual void updateState() = 0;
    virtual nts::ComponentType getType() const = 0;
    virtual std::map<int, std::list<int>> getPinMap() = 0;
    virtual bool operator<(const IComponent& other) const = 0;
};
}
#endif /* !ICOMPONENT_HPP_ */
