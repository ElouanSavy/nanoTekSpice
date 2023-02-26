/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsBinaryOperation
*/

#include "AComponent.hpp"
#include "Circuit.hpp"
#include "FalseComponent.hpp"
#include "FourBitAdderComponent.hpp"
#include "InputComponent.hpp"
#include "Parser.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(FourBitAdder_test_1, FourBitAdder, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4008_adder.nts", circuit), 0);
    circuit.getComponentByName("in_a1")->setActualState(nts::True);
    circuit.getComponentByName("in_a2")->setActualState(nts::True);
    circuit.getComponentByName("in_a3")->setActualState(nts::True);
    circuit.getComponentByName("in_a4")->setActualState(nts::True);
    circuit.getComponentByName("in_b1")->setActualState(nts::False);
    circuit.getComponentByName("in_b2")->setActualState(nts::False);
    circuit.getComponentByName("in_b3")->setActualState(nts::False);
    circuit.getComponentByName("in_b4")->setActualState(nts::False);
    circuit.getComponentByName("in_c")->setActualState(nts::True);
    circuit.simulate();
    cr_assert_eq(circuit.getComponentByName("adder")->compute(10), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(11), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(12), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(13), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(14), nts::True);
}

Test(FourBitAdder_test_2, FourBitAdder, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4008_adder.nts", circuit), 0);
    circuit.getComponentByName("in_a1")->setActualState(nts::False);
    circuit.getComponentByName("in_a2")->setActualState(nts::False);
    circuit.getComponentByName("in_a3")->setActualState(nts::False);
    circuit.getComponentByName("in_a4")->setActualState(nts::False);
    circuit.getComponentByName("in_b1")->setActualState(nts::False);
    circuit.getComponentByName("in_b2")->setActualState(nts::False);
    circuit.getComponentByName("in_b3")->setActualState(nts::False);
    circuit.getComponentByName("in_b4")->setActualState(nts::False);
    circuit.getComponentByName("in_c")->setActualState(nts::True);
    circuit.simulate();
    cr_assert_eq(circuit.getComponentByName("adder")->compute(10), nts::True);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(11), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(12), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(13), nts::False);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(14), nts::False);
}

Test(FourBitAdder_test_3, FourBitAdder, .init = redirect_all_std)
{
    nts::Parser parser;
    nts::Circuit circuit;
    cr_assert_eq(parser.parseFile("tests/assets/subject_tests/4008_adder.nts", circuit), 0);
    circuit.getComponentByName("in_a1")->setActualState(nts::True);
    circuit.getComponentByName("in_a2")->setActualState(nts::True);
    circuit.getComponentByName("in_a3")->setActualState(nts::True);
    circuit.getComponentByName("in_a4")->setActualState(nts::True);
    circuit.getComponentByName("in_b1")->setActualState(nts::True);
    circuit.getComponentByName("in_b2")->setActualState(nts::True);
    circuit.getComponentByName("in_b3")->setActualState(nts::True);
    circuit.getComponentByName("in_b4")->setActualState(nts::True);
    circuit.getComponentByName("in_c")->setActualState(nts::True);
    circuit.simulate();
    cr_assert_eq(circuit.getComponentByName("adder")->compute(10), nts::True);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(11), nts::True);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(12), nts::True);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(13), nts::True);
    cr_assert_eq(circuit.getComponentByName("adder")->compute(14), nts::True);
}
