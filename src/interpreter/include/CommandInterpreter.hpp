/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** CommandInterpreter
*/

#ifndef COMMANDINTERPRETER_HPP_
#define COMMANDINTERPRETER_HPP_

#include "Circuit.hpp"
#include <map>

namespace nts {

class CommandInterpreter {
  public:
    CommandInterpreter();
    ~CommandInterpreter() = default;
    void handleCommand(Circuit& circuit);
    int getCommand(std::string cmd, Circuit& circuit);
    void parseCommand(std::string cmd, Circuit& circuit);

    private:
      std::map<std::string, Tristate> posibleValues_;
};
}

#endif /* !COMMANDINTERPRETER_HPP_ */
