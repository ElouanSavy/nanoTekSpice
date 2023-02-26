/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_
#include "AndCreator.hpp"
#include "BitCounterCreator.hpp"
#include "Circuit.hpp"
#include "ClockCreator.hpp"
#include "DecoderCreator.hpp"
#include "DualFlipFlopCreator.hpp"
#include "Errors.hpp"
#include "FalseCreator.hpp"
#include "FourAndCreator.hpp"
#include "FourBitAdderCreator.hpp"
#include "FourNandCreator.hpp"
#include "FourNorCreator.hpp"
#include "FourOrCreator.hpp"
#include "FourXorCreator.hpp"
#include "ICreator.hpp"
#include "InputCreator.hpp"
#include "JohnsonDecadeCreator.hpp"
#include "LoggerCreator.hpp"
#include "NotCreator.hpp"
#include "OrCreator.hpp"
#include "OutputCreator.hpp"
#include "SixInverterCreator.hpp"
#include "TrueCreator.hpp"
#include "XorCreator.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace nts {
class Parser {
  public:
    Parser();
    ~Parser() = default;
    int parseFile(std::string filename, nts::Circuit& circuit);
    void parseChipset(std::ifstream& fs, nts::Circuit& circuit);
    void createChipset(std::vector<std::string> tokens_, nts::Circuit& circuit);
    void parseLink(std::ifstream& fs, nts::Circuit& circuit);
    void createLink(std::stringstream& ss, nts::Circuit& circuit);
    bool isInMapPin(std::size_t pin, IComponent& component);
    bool isValidPin(std::size_t pin, std::map<int, std::list<int>>& c1Map);
    bool isPossibleLink(std::size_t input, std::size_t output, IComponent& component);
    bool isInputAlreadyLink(std::string name, std::size_t output);
    bool isOutputAlreadyLink(std::string name, std::size_t output);
    std::vector<std::string> parseChipsetLine(std::stringstream& ss);
    std::vector<std::string> parseLinkLine(std::stringstream& ss);
    bool isNum(std::string str);

  private:
    std::map<std::string, std::unique_ptr<ICreator>> creatorMap_;
    std::map<std::string, std::list<std::size_t>> tmpInputSet;
    std::map<std::string, std::list<std::size_t>> tmpOutputSet;
};
}

#endif /* !PARSER_HPP_ */
