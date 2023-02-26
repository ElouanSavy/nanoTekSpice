/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGD09-elouan.savy-camaret
** File description:
** tests
*/

#include "AComponent.hpp"
#include "AndComponent.hpp"
#include "ClockComponent.hpp"
#include "DualFlipFlopComponent.hpp"
#include "FalseComponent.hpp"
#include "FourXorComponent.hpp"
#include "NotComponent.hpp"
#include "OrComponent.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(FlipFlop_ClockTrue_AllFalse, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::False);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::False);

    flipFlop->setLink(3, *clock, 1); // CLOCK
    flipFlop->setLink(4, *input1, 1); // RESET
    flipFlop->setLink(5, *input2, 1); // DATA
    flipFlop->setLink(6, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(1), nts::False);
    cr_assert_eq(flipFlop->compute(2), nts::True);
}

Test(FlipFlop_ClockTrue_AllFalse_OtherPins, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::False);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::False);

    flipFlop->setLink(11, *clock, 1); // CLOCK
    flipFlop->setLink(10, *input1, 1); // RESET
    flipFlop->setLink(9, *input2, 1); // DATA
    flipFlop->setLink(8, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(13), nts::False);
    cr_assert_eq(flipFlop->compute(12), nts::True);
}

Test(FlipFlop_ClockTrue_DataTrue, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::False);
    input2->setActualState(nts::Tristate::True);
    input3->setActualState(nts::Tristate::False);

    flipFlop->setLink(3, *clock, 1); // CLOCK
    flipFlop->setLink(4, *input1, 1); // RESET
    flipFlop->setLink(5, *input2, 1); // DATA
    flipFlop->setLink(6, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(1), nts::True);
    cr_assert_eq(flipFlop->compute(2), nts::False);
}

Test(FlipFlop_ResetTrue_SetFalse, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::True);
    input2->setActualState(nts::Tristate::True);
    input3->setActualState(nts::Tristate::False);

    flipFlop->setLink(3, *clock, 1); // CLOCK
    flipFlop->setLink(4, *input1, 1); // RESET
    flipFlop->setLink(5, *input2, 1); // DATA
    flipFlop->setLink(6, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(1), nts::False);
    cr_assert_eq(flipFlop->compute(2), nts::True);
}

Test(FlipFlop_ResetFalse_SetTrue, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::False);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::True);

    flipFlop->setLink(3, *clock, 1); // CLOCK
    flipFlop->setLink(4, *input1, 1); // RESET
    flipFlop->setLink(5, *input2, 1); // DATA
    flipFlop->setLink(6, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(1), nts::True);
    cr_assert_eq(flipFlop->compute(2), nts::False);
}

Test(FlipFlop_ResetTrue_SetTrue, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::True);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::True);

    flipFlop->setLink(3, *clock, 1); // CLOCK
    flipFlop->setLink(4, *input1, 1); // RESET
    flipFlop->setLink(5, *input2, 1); // DATA
    flipFlop->setLink(6, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(1), nts::True);
    cr_assert_eq(flipFlop->compute(2), nts::True);
}

Test(FlipFlop_ResetTrue_SetTrue_OtherPins, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::True);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::True);

    flipFlop->setLink(11, *clock, 1); // CLOCK
    flipFlop->setLink(10, *input1, 1); // RESET
    flipFlop->setLink(9, *input2, 1); // DATA
    flipFlop->setLink(8, *input3, 1); // SET
    cr_assert_eq(flipFlop->compute(13), nts::True);
    cr_assert_eq(flipFlop->compute(12), nts::True);
}

Test(FlipFlop_ClockFalse, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::True);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::True);

    flipFlop->setLink(3, *clock, 1); // CLOCK
    flipFlop->setLink(4, *input1, 1); // RESET
    flipFlop->setLink(5, *input2, 1); // DATA
    flipFlop->setLink(6, *input3, 1); // SET

    flipFlop->compute(1);
    flipFlop->compute(2);

    input1->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::False);
    clock->setActualState(nts::Tristate::False);

    cr_assert_eq(flipFlop->compute(1), nts::True);
    cr_assert_eq(flipFlop->compute(2), nts::True);
}

Test(FlipFlop_ClockFalse_OtherPins, FlipFlop_Component, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> input3 = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    std::unique_ptr<nts::IComponent> flipFlop = std::make_unique<nts::DualFlipFlopComponent>();
    clock->setActualState(nts::Tristate::True);
    input1->setActualState(nts::Tristate::True);
    input2->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::True);

    flipFlop->setLink(11, *clock, 1); // CLOCK
    flipFlop->setLink(10, *input1, 1); // RESET
    flipFlop->setLink(9, *input2, 1); // DATA
    flipFlop->setLink(8, *input3, 1); // SET

    flipFlop->compute(13);
    flipFlop->compute(12);

    input1->setActualState(nts::Tristate::False);
    input3->setActualState(nts::Tristate::False);
    clock->setActualState(nts::Tristate::False);

    cr_assert_eq(flipFlop->compute(13), nts::True);
    cr_assert_eq(flipFlop->compute(12), nts::True);
}