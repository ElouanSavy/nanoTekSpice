/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestParsingSubject
*/

#include "Parser.hpp"
#include "Circuit.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(ParsingErrors, one_out_2_in, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/1output_2inputs.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, two_in_1_out, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/2input_1output.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, chip_before_tag, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/chipset_before_tag.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, no_chipsets_tag, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/no_chipsets_tag.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, no_chipsets, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/no_chipsets.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, no_name, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/no_name.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, no_pins, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/no_pins.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, same_name, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/same_name.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, wrong_gate, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/wrong_gate.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, wrong_pin, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/wrong_pin.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, no_chipset, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/no_chipset.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, error1, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/error1.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, error2, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/error2.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, error3, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/error3.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingErrors, error4, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/failed/error4.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}
