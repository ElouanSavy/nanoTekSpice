/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <algorithm>

void nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> component)
{
    this->componentList_.push_back(std::move(component));
    std::sort(std::begin(this->componentList_), std::end(this->componentList_), [](const std::unique_ptr<nts::IComponent>& a, const std::unique_ptr<nts::IComponent>& b) {
        return a->getName() < b->getName();
    });
    return;
}

void nts::Circuit::simulate()
{
    this->tick_ += 1;
    IComponent* cmp;
    for (std::size_t i = 0; i < this->componentList_.size(); i++)
        this->componentList_[i]->simulate(0);

    // update les composant selon nextUpdate
    for (std::pair<std::string, nts::Tristate> pair : this->nextUpdate_) {
        cmp = this->getComponentByName(pair.first);
        if (cmp) {
            cmp->setActualState(pair.second);
        }
    }
    this->nextUpdate_.clear();
    this->updateAllStates();
}

void nts::Circuit::updateAllStates() const
{
    for (std::size_t i = 0; i < this->componentList_.size(); i++)
        this->componentList_[i]->updateState();
}

void nts::Circuit::showInputs() const
{

    std::cout << "tick: " << this->tick_ << "\n";
    std::cout << "input(s):\n";
    for (std::size_t i = 0; i < this->componentList_.size(); i++)
        if (this->componentList_[i]->getType() == INPUT)
            std::cout << "  " << this->componentList_[i]->getName() << ": " << this->displayTristate(this->componentList_[i]->compute(1)) << "\n";
}

void nts::Circuit::showOutputs() const
{
    std::cout << "output(s):\n";
    for (std::size_t i = 0; i < this->componentList_.size(); i++)
        if (this->componentList_[i]->getType() == OUTPUT)
            std::cout << "  " << this->componentList_[i]->getName() << ": " << this->displayTristate(this->componentList_[i]->compute(0)) << "\n";
}

nts::IComponent* nts::Circuit::getComponentByName(const std::string name)
{
    for (std::size_t i = 0; i < this->componentList_.size(); i++) {
        if (this->componentList_[i]->getName() == name) {
            return this->componentList_[i].get();
        }
    }
    return nullptr;
}

void nts::Circuit::dumpCircuit() const
{
    for (std::size_t i = 0; i < this->componentList_.size(); i++) {
        std::cout << "Name : " << this->componentList_[i]->getName() << "\n";
    }
}

std::string nts::Circuit::displayTristate(Tristate state) const
{
    if (state == Tristate::Undefined)
        return "U";
    if (state == Tristate::True)
        return "1";
    return "0";
}

void nts::Circuit::addComponentToUpdate(std::string name, nts::Tristate state)
{
    this->nextUpdate_.push_back(std::pair<std::string, nts::Tristate>(name, state));
}

std::size_t nts::Circuit::getComponentListSize() const
{
    return this->componentList_.size();
}
