/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** CommandInterpreter
*/

#include "CommandInterpreter.hpp"
#include <iostream>

nts::CommandInterpreter::CommandInterpreter()
{
    this->posibleValues_["U"] = Tristate::Undefined;
    this->posibleValues_["0"] = Tristate::False;
    this->posibleValues_["1"] = Tristate::True;
}

void nts::CommandInterpreter::parseCommand(std::string cmd, nts::Circuit& circuit)
{
    std::string gate;
    std::string value;
    std::size_t pos = cmd.find("=");
    IComponent* gateComponent;
    if (pos == std::string::npos)
        return;
    gate = cmd.substr(0, pos);
    cmd.erase(0, pos + 1);
    if (cmd.find("=") != std::string::npos)
        return;
    value = cmd;
    gateComponent = circuit.getComponentByName(gate);
    if (!gateComponent || (this->posibleValues_.find(value) == this->posibleValues_.end()))
        return;
    // circuit->nextUpdate (map (name, futur state))
    circuit.addComponentToUpdate(gate, this->posibleValues_[value]);
    return;
}

int nts::CommandInterpreter::getCommand(std::string cmd, nts::Circuit& circuit)
{
    if (cmd == "display") {
        circuit.showInputs();
        circuit.showOutputs();
    } else if (cmd == "simulate") {
        circuit.simulate();
    } else if (cmd == "loop") {
        while (1) {
            circuit.simulate();
            circuit.showInputs();
            circuit.showOutputs();
        }
    } else if (cmd == "exit") {
        return 1;
    } else {
        this->parseCommand(cmd, circuit);
    }
    return 0;
}

void nts::CommandInterpreter::handleCommand(nts::Circuit& circuit)
{
    std::string cmd;
    std::cout << "> ";
    while (std::getline(std::cin, cmd)) {
        if (this->getCommand(cmd, circuit))
            return;
        std::cout << "> ";
    }
    return;
}
