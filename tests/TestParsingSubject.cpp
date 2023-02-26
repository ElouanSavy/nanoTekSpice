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

Test(ParsingSubject, 4001_nor, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4001_nor.nts", circuit), 0);
}

Test(ParsingSubject, 4008_adder, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4008_adder.nts", circuit), 0);
}

Test(ParsingSubject, 4011_nand, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4011_nand.nts", circuit), 0);
}

Test(ParsingSubject, 4013_flipflop, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4013_flipflop.nts", circuit), 0);
}

Test(ParsingSubject, 4017_johnson, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4017_johnson.nts", circuit), 0);
}

Test(ParsingSubject, 4030_xor, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4030_xor.nts", circuit), 0);
}

Test(ParsingSubject, 4069_not, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4069_not.nts", circuit), 0);
}

Test(ParsingSubject, 4071_or, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4071_or.nts", circuit), 0);
}

Test(ParsingSubject, 4081_and, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4081_and.nts", circuit), 0);
}

Test(ParsingSubject, and, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/and.nts", circuit), 0);
}

Test(ParsingSubject, clock, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/clock.nts", circuit), 0);
}

Test(ParsingSubject, false, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/false.nts", circuit), 0);
}

Test(ParsingSubject, input_output, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/input_output.nts", circuit), 0);
}

Test(ParsingSubject, logger, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/logger.nts", circuit), 0);
}

Test(ParsingSubject, not, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/not.nts", circuit), 0);
}

Test(ParsingSubject, or, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/or.nts", circuit), 0);
}

Test(ParsingSubject, true, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/true.nts", circuit), 0);
}

Test(ParsingSubject, xor, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/xor.nts", circuit), 0);
}

Test(ParsingSubject, andOrNot, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/and-or-notCircuit.nts", circuit), 0);
}

Test(ParsingSubject, andCircuit, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/andCircuit.nts", circuit), 0);
}

Test(ParsingSubject, Example1, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/example_1.nts", circuit), 0);
}

Test(ParsingSubject, Example2, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    int catched = false;
    try {
        parser.parseFile("tests/assets/subject_tests/example_2.nts", circuit);
    } catch (nts::ParsingError& e) {
        catched = true;
    }
    cr_assert_eq(catched, true);
}

Test(ParsingSubject, Example3, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/example_3.nts", circuit), 0);
}

Test(ParsingSubject, one_chipset, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/one_chipset.nts", circuit), 0);
}

Test(ParsingSubject, comment_1, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/comment1.nts", circuit), 0);
}

Test(ParsingSubject, comment_2, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/comment2.nts", circuit), 0);
}

Test(ParsingSubject, comment_3, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/comment3.nts", circuit), 0);
}

Test(ParsingSubject, comment_4, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/comment4.nts", circuit), 0);
}

Test(ParsingSubject, comment_5, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/comment5.nts", circuit), 0);
}
