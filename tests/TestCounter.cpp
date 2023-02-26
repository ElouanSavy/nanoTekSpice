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

Test(Counter, Counter, .init = redirect_all_std)
{
    nts::Circuit circuit;
    nts::Parser parser;
    parser.parseFile("tests/assets/subject_tests/4040_counter.nts", circuit);
    nts::IComponent* gate = circuit.getComponentByName("counter");
    nts::IComponent* clock = circuit.getComponentByName("cl_clock");
    nts::IComponent* reset = circuit.getComponentByName("in_reset");
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    clock->setActualState(nts::Tristate::False);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(gate->compute(9), 1);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    circuit.simulate();
    cr_assert_eq(gate->compute(9), 1);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    circuit.simulate();
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(7), 1);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(gate->compute(9), 1);
    cr_assert_eq(gate->compute(7), 1);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 1);
    cr_assert_eq(gate->compute(5), 1);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    reset->setActualState(nts::Tristate::True);
    circuit.simulate();
    cr_assert_eq(gate->compute(9), 0);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
    circuit.simulate(); // Test du reset avec la clock a False, donc avance a 1 direct.
    cr_assert_eq(gate->compute(9), 1);
    cr_assert_eq(gate->compute(7), 0);
    cr_assert_eq(gate->compute(6), 0);
    cr_assert_eq(gate->compute(5), 0);
    cr_assert_eq(gate->compute(3), 0);
    cr_assert_eq(gate->compute(2), 0);
    cr_assert_eq(gate->compute(4), 0);
    cr_assert_eq(gate->compute(13), 0);
    cr_assert_eq(gate->compute(12), 0);
    cr_assert_eq(gate->compute(14), 0);
    cr_assert_eq(gate->compute(15), 0);
    cr_assert_eq(gate->compute(1), 0);
}
