/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsBinaryOperation
*/

#include "AComponent.hpp"
#include "Circuit.hpp"
#include "ClockComponent.hpp"
#include "FalseComponent.hpp"
#include "Parser.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(Decoder, Decoder, .init = redirect_all_std)
{
    nts::Circuit circuit;
    nts::Parser parser;
    parser.parseFile("tests/assets/subject_tests/4514_decoder.nts", circuit);
    nts::IComponent* gate = circuit.getComponentByName("decoder");
    nts::IComponent* in_0 = circuit.getComponentByName("in_0");
    nts::IComponent* in_1 = circuit.getComponentByName("in_1");
    nts::IComponent* in_2 = circuit.getComponentByName("in_2");
    nts::IComponent* in_3 = circuit.getComponentByName("in_3");
    nts::IComponent* strobe = circuit.getComponentByName("strobe");
    nts::IComponent* inhib = circuit.getComponentByName("inhibit");
    cr_assert_eq(gate->compute(11), -1);
    cr_assert_eq(gate->compute(9), -1);
    cr_assert_eq(gate->compute(10), -1);
    cr_assert_eq(gate->compute(8), -1);
    cr_assert_eq(gate->compute(7), -1);
    cr_assert_eq(gate->compute(6), -1);
    cr_assert_eq(gate->compute(5), -1);
    cr_assert_eq(gate->compute(4), -1);
    cr_assert_eq(gate->compute(18), -1);
    cr_assert_eq(gate->compute(17), -1);
    cr_assert_eq(gate->compute(20), -1);
    cr_assert_eq(gate->compute(19), -1);
    cr_assert_eq(gate->compute(14), -1);
    cr_assert_eq(gate->compute(13), -1);
    cr_assert_eq(gate->compute(16), -1);
    cr_assert_eq(gate->compute(15), -1);
    strobe->setActualState(nts::Tristate::True);
    in_2->setActualState(nts::Tristate::True);
    circuit.simulate();
    cr_assert_eq(gate->compute(11), -1);
    cr_assert_eq(gate->compute(9), -1);
    cr_assert_eq(gate->compute(10), -1);
    cr_assert_eq(gate->compute(8), -1);
    cr_assert_eq(gate->compute(7), -1);
    cr_assert_eq(gate->compute(6), -1);
    cr_assert_eq(gate->compute(5), -1);
    cr_assert_eq(gate->compute(4), -1);
    cr_assert_eq(gate->compute(18), -1);
    cr_assert_eq(gate->compute(17), -1);
    cr_assert_eq(gate->compute(20), -1);
    cr_assert_eq(gate->compute(19), -1);
    cr_assert_eq(gate->compute(14), -1);
    cr_assert_eq(gate->compute(13), -1);
    cr_assert_eq(gate->compute(16), -1);
    cr_assert_eq(gate->compute(15), -1);
    strobe->setActualState(nts::Tristate::False);
    in_0->setActualState(nts::Tristate::False);
    in_1->setActualState(nts::Tristate::False);
    in_3->setActualState(nts::Tristate::False);
    circuit.simulate();
    strobe->setActualState(nts::Tristate::True);
    circuit.simulate();
    cr_assert_eq(gate->compute(11), 0);
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(10), 0);
    cr_assert_eq(gate->compute(8), 0);
    cr_assert_eq(gate->compute(7), 1);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(18), 0);
    cr_assert_eq(gate->compute(17), 0);
    cr_assert_eq(gate->compute(20), 0);
    cr_assert_eq(gate->compute(19), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(16), 0);
    cr_assert_eq(gate->compute(15), 0);
    strobe->setActualState(nts::Tristate::False);
    circuit.simulate();
    strobe->setActualState(nts::Tristate::True);
    inhib->setActualState(nts::Tristate::True);
    in_0->setActualState(nts::Tristate::True);
    in_1->setActualState(nts::Tristate::True);
    in_3->setActualState(nts::Tristate::True);
    circuit.simulate();
    cr_assert_eq(gate->compute(11), 0);
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(10), 0);
    cr_assert_eq(gate->compute(8), 0);
    cr_assert_eq(gate->compute(7), 1);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(18), 0);
    cr_assert_eq(gate->compute(17), 0);
    cr_assert_eq(gate->compute(20), 0);
    cr_assert_eq(gate->compute(19), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(16), 0);
    cr_assert_eq(gate->compute(15), 0);
    inhib->setActualState(nts::Tristate::False);
    strobe->setActualState(nts::Tristate::False);
    circuit.simulate();
    strobe->setActualState(nts::Tristate::True);
    circuit.simulate();
    cr_assert_eq(gate->compute(11), 0);
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(10), 0);
    cr_assert_eq(gate->compute(8), 0);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(18), 0);
    cr_assert_eq(gate->compute(17), 0);
    cr_assert_eq(gate->compute(20), 0);
    cr_assert_eq(gate->compute(19), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(16), 0);
    cr_assert_eq(gate->compute(15), 1);
    strobe->setActualState(nts::Tristate::False);
    circuit.simulate();
    strobe->setActualState(nts::Tristate::True);
    in_1->setActualState(nts::Tristate::Undefined);
    circuit.simulate();
    cr_assert_eq(gate->compute(11), -1);
    cr_assert_eq(gate->compute(9), -1);
    cr_assert_eq(gate->compute(10), -1);
    cr_assert_eq(gate->compute(8), -1);
    cr_assert_eq(gate->compute(7), -1);
    cr_assert_eq(gate->compute(6), -1);
    cr_assert_eq(gate->compute(5), -1);
    cr_assert_eq(gate->compute(4), -1);
    cr_assert_eq(gate->compute(18), -1);
    cr_assert_eq(gate->compute(17), -1);
    cr_assert_eq(gate->compute(20), -1);
    cr_assert_eq(gate->compute(19), -1);
    cr_assert_eq(gate->compute(14), -1);
    cr_assert_eq(gate->compute(13), -1);
    cr_assert_eq(gate->compute(16), -1);
    cr_assert_eq(gate->compute(15), -1);
}
