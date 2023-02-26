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
#include "JohnsonDecadeComponent.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(JohnsonDecade, JohnsonDecade, .init = redirect_all_std)
{
    nts::Circuit circuit;
    std::unique_ptr<nts::IComponent> inputTrue_ = std::make_unique<nts::TrueComponent>("True");
    std::unique_ptr<nts::IComponent> inputFalse_ = std::make_unique<nts::FalseComponent>("False");
    std::unique_ptr<nts::IComponent> jDecade_ = std::make_unique<nts::JohnsonDecadeComponent>("Decade");
    std::unique_ptr<nts::IComponent> clock_ = std::make_unique<nts::ClockComponent>("Clock");

    circuit.addComponent(std::move(inputTrue_));
    circuit.addComponent(std::move(inputFalse_));
    circuit.addComponent(std::move(jDecade_));
    circuit.addComponent(std::move(clock_));

    nts::IComponent* inputTrue = circuit.getComponentByName("True");
    nts::IComponent* inputFalse = circuit.getComponentByName("False");
    nts::IComponent* jDecade = circuit.getComponentByName("Decade");
    nts::IComponent* clock = circuit.getComponentByName("Clock");

    clock->setActualState(nts::False);
    jDecade->setLink(14, *clock, 1);
    jDecade->setLink(13, *inputFalse, 1);
    jDecade->setLink(15, *inputTrue, 1);
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    jDecade->setLink(15, *inputFalse, 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 1);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 1);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 1);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 1);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 1);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 0);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 1);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 0);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 1);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 0);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 1);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 0);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 1);
    cr_assert_eq(jDecade->compute(12), 0);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    jDecade->setLink(15, *inputFalse, 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 1);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 1);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    jDecade->setLink(15, *inputTrue, 1);
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    jDecade->setLink(15, *inputFalse, 1);
    jDecade->setLink(13, *inputTrue, 1);
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    jDecade->setLink(13, *inputFalse, 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 1);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 1);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 1);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 1);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 0);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 1);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 0);
    circuit.simulate();
    jDecade->setLink(15, *inputTrue, 1);
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
    circuit.simulate();
    circuit.simulate();
    cr_assert_eq(jDecade->compute(3), 1);
    cr_assert_eq(jDecade->compute(2), 0);
    cr_assert_eq(jDecade->compute(4), 0);
    cr_assert_eq(jDecade->compute(7), 0);
    cr_assert_eq(jDecade->compute(10), 0);
    cr_assert_eq(jDecade->compute(1), 0);
    cr_assert_eq(jDecade->compute(5), 0);
    cr_assert_eq(jDecade->compute(6), 0);
    cr_assert_eq(jDecade->compute(9), 0);
    cr_assert_eq(jDecade->compute(11), 0);
    cr_assert_eq(jDecade->compute(12), 1);
}
