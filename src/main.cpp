/*
** EPITECH PROJECT, 2023
** Nano-Bootstrap
** File description:
** main
*/

#include "AComponent.hpp"
#include "AndComponent.hpp"
#include "Circuit.hpp"
#include "ClockComponent.hpp"
#include "CommandInterpreter.hpp"
#include "DualFlipFlopComponent.hpp"
#include "FalseComponent.hpp"
#include "InputComponent.hpp"
#include "NotComponent.hpp"
#include "OutputComponent.hpp"
#include "Parser.hpp"
#include "TrueComponent.hpp"
#include <memory>

int main(int argc, char** argv)
{
    if (argc != 2)
        return 84;
    nts::Circuit circuit;
    nts::Parser parser;
    nts::CommandInterpreter interpreter;
    try {
        parser.parseFile(argv[1], circuit);
    } catch (nts::ParsingError& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 84;
    }

    try {
        interpreter.handleCommand(circuit);
    } catch (nts::ComputeError& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 84;
    }
    return 0;
}
