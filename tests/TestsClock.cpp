/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGD09-elouan.savy-camaret
** File description:
** tests
*/

#include "AComponent.hpp"
#include "AndComponent.hpp"
#include "FalseComponent.hpp"
#include "FourXorComponent.hpp"
#include "NotComponent.hpp"
#include "OrComponent.hpp"
#include "SixInverterComponent.hpp"
#include "TrueComponent.hpp"
#include "ClockComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(ClockComponent_Init, ClockComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    cr_assert_eq(clock->compute(1), nts::Undefined);
}

Test(ClockComponent_SetTrue, ClockComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    clock->setActualState(nts::True);
    cr_assert_eq(clock->compute(1), nts::True);
}

Test(ClockComponent_Simulate, ClockComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> clock = std::make_unique<nts::ClockComponent>();
    clock->setActualState(nts::True);
    clock->simulate(1);
    cr_assert_eq(clock->compute(1), nts::False);
}
