/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include <memory>
namespace nts {
class Circuit {
  public:
    Circuit() = default;
    ~Circuit() = default;
    void simulate();
    void addComponent(std::unique_ptr<nts::IComponent> component);
    IComponent* getComponentByName(const std::string name);
    void showInputs() const;
    void showOutputs() const;
    void updateAllStates() const;
    void dumpCircuit() const;
    std::string displayTristate(Tristate state) const;
    void addComponentToUpdate(std::string name, nts::Tristate);
    std::size_t getComponentListSize() const;

  private:
    std::vector<std::unique_ptr<nts::IComponent>> componentList_ {};
    int tick_ { 0 };
    std::vector<std::pair<std::string, nts::Tristate>> nextUpdate_;
};
}

#endif /* !CIRCUIT_HPP_ */
