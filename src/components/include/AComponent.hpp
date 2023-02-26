/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "Errors.hpp"
#include "IComponent.hpp"
#include <utility>

namespace nts {
class BinaryOperation {
  public:
    BinaryOperation() = default;
    ~BinaryOperation() = default;
    Tristate and_(Tristate a, Tristate b);
    Tristate nand_(Tristate a, Tristate b);
    Tristate nor_(Tristate a, Tristate b);
    Tristate or_(Tristate a, Tristate b);
    Tristate xor_(Tristate a, Tristate b);
};

class AComponent : public IComponent {
  public:
    ~AComponent() = default;
    void simulate(std::size_t tick) override;
    void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
    nts::Tristate getLink(std::size_t pin) const; //* Utilisée uniquement dans la methode compute donc pas dans l'interface
    void setActualState(Tristate state) override;
    std::string getName() const override;
    void updateState() override;
    nts::ComponentType getType() const override;
    std::map<int, std::list<int>> getPinMap() override;
    bool operator<(const IComponent& other) const override;

  protected:
    BinaryOperation binaryOperator;
    std::map<int, std::pair<IComponent*, int>> input_;
    std::map<int, std::list<int>> pinMap_;
    std::string name_;
    nts::ComponentType type_ { OTHER };
};
Tristate operator!(Tristate op);
}

#endif /* !ACOMPONENT_HPP_ */
