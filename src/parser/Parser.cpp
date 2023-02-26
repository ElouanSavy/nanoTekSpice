/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** Parser
*/

#include "Parser.hpp"
#include <algorithm>
#include <cstring>
#include <memory>

bool nts::Parser::isValidPin(std::size_t pin, std::map<int, std::list<int>>& c1Map)
{
    for (std::pair<int, std::list<int>> index : c1Map) {
        for (std::size_t tmp : index.second) {
            if (tmp == pin)
                return true;
        }
    }
    return false;
}

bool nts::Parser::isInMapPin(std::size_t pin, IComponent& component)
{
    std::map<int, std::list<int>> c1Map = component.getPinMap();

    bool found = c1Map.find(pin) != c1Map.end();

    if (!found && !this->isValidPin(pin, c1Map)) {
        throw nts::ParsingError("Invalid pin");
    }

    return (found);
}

bool nts::Parser::isPossibleLink(std::size_t input, std::size_t output, IComponent& component)
{
    std::map<int, std::list<int>> c1Map = component.getPinMap();

    for (std::size_t pin : c1Map[output]) {
        if (pin == input)
            return false;
    }

    return true;
}

bool nts::Parser::isInputAlreadyLink(std::string name, std::size_t input)
{
    for (std::size_t pin : this->tmpInputSet[name]) {
        if (pin == input)
            return true;
    }

    this->tmpInputSet[name].push_back(input);
    return false;
}

bool nts::Parser::isOutputAlreadyLink(std::string name, std::size_t output)
{
    for (std::size_t pin : this->tmpOutputSet[name]) {
        if (pin == output)
            return true;
    }

    this->tmpOutputSet[name].push_back(output);
    return false;
}

nts::Parser::Parser()
{
    this->creatorMap_["or"] = std::make_unique<OrCreator>();
    this->creatorMap_["input"] = std::make_unique<InputCreator>();
    this->creatorMap_["output"] = std::make_unique<OutputCreator>();
    this->creatorMap_["false"] = std::make_unique<FalseCreator>();
    this->creatorMap_["true"] = std::make_unique<TrueCreator>();
    this->creatorMap_["clock"] = std::make_unique<ClockCreator>();
    this->creatorMap_["and"] = std::make_unique<AndCreator>();
    this->creatorMap_["4081"] = std::make_unique<FourAndCreator>();
    this->creatorMap_["4011"] = std::make_unique<FourNandCreator>();
    this->creatorMap_["4001"] = std::make_unique<FourNorCreator>();
    this->creatorMap_["4030"] = std::make_unique<FourXorCreator>();
    this->creatorMap_["4069"] = std::make_unique<SixInverterCreator>();
    this->creatorMap_["xor"] = std::make_unique<XorCreator>();
    this->creatorMap_["4040"] = std::make_unique<BitCounterCreator>();
    this->creatorMap_["4013"] = std::make_unique<DualFlipFlopCreator>();
    this->creatorMap_["4008"] = std::make_unique<FourBitAdderCreator>();
    this->creatorMap_["4017"] = std::make_unique<JohnsonDecadeCreator>();
    this->creatorMap_["4514"] = std::make_unique<DecoderCreator>();
    this->creatorMap_["4071"] = std::make_unique<FourOrCreator>();
    this->creatorMap_["not"] = std::make_unique<NotCreator>();
    this->creatorMap_["logger"] = std::make_unique<LoggerCreator>();
}

bool nts::Parser::isNum(std::string src)
{
    if (src.length() == 0)
        return false;

    for (size_t i = 0; i < src.length(); i++) {
        if (!std::isdigit(src[i]))
            return false;
    }
    return true;
}

std::vector<std::string> nts::Parser::parseChipsetLine(std::stringstream& ss)
{
    std::vector<std::string> tokens;
    std::string tmp;
    while (ss >> tmp) {
        if (tmp[0] == '#' || tmp.empty())
            break;
        if (tmp.find('#') != std::string::npos) {
            tmp.erase(tmp.find('#'), tmp.length() - 1);
            tokens.push_back(tmp);
            break;
        }
        tokens.push_back(tmp);
    }

    if (!tokens.empty() && tokens.back().find('#') != std::string::npos) {
        tokens.back().erase(tokens.back().find('#'), tokens.back().length() - 1);
    }

    return tokens;
}

std::vector<std::string> nts::Parser::parseLinkLine(std::stringstream& ss)
{
    std::vector<std::string> tokens;
    std::string tmp;
    std::string delimiter = ":";
    std::size_t pos = 0;
    std::string token;
    bool endParsing = false;

    while ((ss >> tmp) && !endParsing) {
        if (tmp[0] == '#' || tmp.empty())
            break;
        if (tmp.find('#') != std::string::npos) {
            tmp.erase(tmp.find('#'), tmp.length() - 1);
            endParsing = true;
        }
        if (std::count(tmp.begin(), tmp.end(), ':') != 1)
            throw ParsingError("Invalid configuration file: link");
        while ((pos = tmp.find(delimiter)) != std::string::npos) {
            token = tmp.substr(0, pos);
            tokens.push_back(token);
            tmp.erase(0, pos + delimiter.length());
        }
        tokens.push_back(tmp);
    }

    if (!tokens.empty() && tokens.back().find('#') != std::string::npos) {
        tokens.back().erase(tokens.back().find('#'), tokens.back().length() - 1);
    }

    return tokens;
}

void nts::Parser::parseChipset(std::ifstream& fs, nts::Circuit& circuit)
{
    std::string tmp = "";

    while (getline(fs, tmp) && (tmp[0] == '#' || tmp.empty()))
        ;

    std::stringstream ssChipset;
    ssChipset << tmp;
    std::vector<std::string> chipsetLine = parseChipsetLine(ssChipset);

    if (chipsetLine.size() != 1 || chipsetLine[0] != ".chipsets:")
        throw ParsingError("Invalid file format");

    while (getline(fs, tmp)) {
        std::stringstream ss;
        ss << tmp;
        chipsetLine = parseChipsetLine(ss);
        if ((chipsetLine.size() == 1) && (chipsetLine[0] == ".links:"))
            return;
        this->createChipset(chipsetLine, circuit);
    }
}

void nts::Parser::createChipset(std::vector<std::string> tokens_, nts::Circuit& circuit)
{
    if (tokens_.size() == 0)
        return;

    if (tokens_.size() != 2) {
        throw nts::ParsingError("Invalid configuration file: chipset");
    }

    if (this->creatorMap_.find(tokens_[0]) == this->creatorMap_.end())
        throw ParsingError("Invalid type of chipset");

    if (circuit.getComponentByName(tokens_[1]))
        throw ParsingError("Name already used");

    circuit.addComponent(this->creatorMap_[tokens_[0]]->createComponent(tokens_[1]));
}

void nts::Parser::parseLink(std::ifstream& fs, nts::Circuit& circuit)
{
    std::string tmp = "";

    while (getline(fs, tmp)) {
        std::stringstream ss;
        ss << tmp;
        this->createLink(ss, circuit);
    }
}

void nts::Parser::createLink(std::stringstream& ss, nts::Circuit& circuit)
{
    std::vector<std::string> tokens_ = parseLinkLine(ss);

    if (tokens_.size() == 0)
        return;

    if (tokens_.size() != 4) {
        std::cout << tokens_.size() << std::endl;
        throw nts::ParsingError("Invalid configuration file: nb link");
    }

    if (!this->isNum(tokens_[1]) || !this->isNum(tokens_[3])) {
        throw nts::ParsingError("Invalid link");
    }

    nts::IComponent* c1 = circuit.getComponentByName(tokens_[0]);
    nts::IComponent* c2 = circuit.getComponentByName(tokens_[2]);

    if (!c1 || !c2) {
        throw nts::ParsingError("Invalid component name");
    }

    if (this->isInMapPin(std::stoll(tokens_[1]), *c1) && !this->isInMapPin(std::stoll(tokens_[3]), *c2)) {
        if ((c1 == c2) && !this->isPossibleLink(std::stoll(tokens_[3].c_str()), std::stoll(tokens_[1].c_str()), *c1))
            throw nts::ParsingError("Invalid link");
        if (this->isInputAlreadyLink(tokens_[2], std::stoll(tokens_[3].c_str())))
            throw nts::ParsingError("Rebinding intput");
        if (this->isOutputAlreadyLink(tokens_[0], std::stoll(tokens_[1].c_str())))
            throw nts::ParsingError("Rebinding output");
        circuit.getComponentByName(tokens_[2])->setLink(std::stoll(tokens_[3].c_str()), *(circuit.getComponentByName(tokens_[0])), std::stoll(tokens_[1].c_str()));
    } else if (!this->isInMapPin(std::stoll(tokens_[1]), *c1) && this->isInMapPin(std::stoll(tokens_[3]), *c2)) {
        if ((c1 == c2) && !this->isPossibleLink(std::stoll(tokens_[1].c_str()), std::stoll(tokens_[3].c_str()), *c1))
            throw nts::ParsingError("Invalid link");
        if (this->isInputAlreadyLink(tokens_[0], std::stoll(tokens_[1].c_str())))
            throw nts::ParsingError("Rebinding input");
        if (this->isOutputAlreadyLink(tokens_[2], std::stoll(tokens_[3].c_str())))
            throw nts::ParsingError("Rebinding output");
        circuit.getComponentByName(tokens_[0])->setLink(std::stoll(tokens_[1].c_str()), *(circuit.getComponentByName(tokens_[2])), std::stoll(tokens_[3].c_str()));
    } else {
        throw nts::ParsingError("Invalid circuit");
    }
}

int nts::Parser::parseFile(std::string filename, nts::Circuit& circuit)
{
    std::ifstream fs(filename);
    std::string tmp;

    if (!fs.is_open()) {
        throw nts::ParsingError(strerror(errno));
    }

    this->parseChipset(fs, circuit);
    this->parseLink(fs, circuit);

    if (circuit.getComponentListSize() < 1)
        throw ParsingError("Circuit must contain at least 1 chipset");

    return 0;
}
