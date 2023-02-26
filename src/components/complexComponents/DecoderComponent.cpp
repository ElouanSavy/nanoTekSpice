/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** DecoderComponent
*/

#include "DecoderComponent.hpp"

nts::DecoderComponent::DecoderComponent(std::string name)
{
    this->name_ = name;
    this->allPins_.fill(Undefined);
    this->pinMap_[11] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[9] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[10] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[8] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[7] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[6] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[5] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[4] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[18] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[17] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[20] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[19] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[14] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[13] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[16] = { 2, 3, 21, 22, 1, 23 };
    this->pinMap_[15] = { 2, 3, 21, 22, 1, 23 };
}

nts::Tristate nts::DecoderComponent::compute(std::size_t pin)
{
    if (this->pinMap_.find(pin) == this->pinMap_.end()) {
        throw nts::ComputeError("Invalid pin for compute");
    }

    return this->allPins_[this->indexMap_[pin]];
}

void nts::DecoderComponent::updateState()
{
    std::list<int> inputList = this->pinMap_[11];
    std::vector<Tristate> resultList;
    int val = 0;

    for (int input : inputList) {
        resultList.push_back(this->getLink(input));
    }
    if (resultList[4] == this->previousState_)
        return;
    this->previousState_ = resultList[4];
    if (resultList[4] != True || resultList[5] == True)
        return;
    if (resultList[3] == Undefined || resultList[2] == Undefined || resultList[1] == Undefined || resultList[0] == Undefined) {
        for (size_t i = 0; i < allPins_.size(); i++)
            allPins_[i] = Undefined;
        return;
    }
    for (size_t i = 0; i < allPins_.size(); i++)
        allPins_[i] = False;
    if (resultList[3] == True)
        val += 8;
    if (resultList[2] == True)
        val += 4;
    if (resultList[1] == True)
        val += 2;
    if (resultList[0] == True)
        val += 1;
    this->allPins_[val] = True;
}
