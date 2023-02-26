/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
    return;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    this->input_[pin] = std::make_pair(&other, otherPin);
}

nts::Tristate nts::AComponent::getLink(std::size_t pin) const
{
    std::pair<IComponent*, int> tmp;
    //* Récupère la puce précédente et son pin de sortie (relié au pin d'entré donné en paramètre)
    if (this->input_.find(pin) != this->input_.end()) {
        tmp = this->input_.at(pin);
    } else {
        return Undefined;
    }

    //* retourne la valeur calculée de la puce précédente
    return tmp.first->compute(tmp.second);
}

void nts::AComponent::setActualState(Tristate state)
{
    (void)state;
    return;
}

nts::Tristate nts::operator!(nts::Tristate op)
{
    if (op == nts::Tristate::Undefined)
        return op;
    return ((op == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True);
}

std::string nts::AComponent::getName() const
{
    return this->name_;
}

void nts::AComponent::updateState()
{
    return;
}

nts::ComponentType nts::AComponent::getType() const
{
    return this->type_;
}

std::map<int, std::list<int>> nts::AComponent::getPinMap()
{
    return this->pinMap_;
}

bool nts::AComponent::operator<(const nts::IComponent& other) const
{
    return this->getName() < other.getName();
}
