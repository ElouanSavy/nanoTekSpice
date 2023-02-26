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
#include "XorComponent.hpp"
#include "InputComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(NotComponent_TrueToFalse, NotComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> not_ = std::make_unique<nts::NotComponent>();
    not_->setLink(1, *inputTrue, 1);
    cr_assert_eq(not_->compute(2), nts::False);
}

Test(NotComponent_Undefined, NotComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> input = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> not_ = std::make_unique<nts::NotComponent>();
    not_->setLink(1, *input, 1);
    cr_assert_eq(not_->compute(2), nts::Undefined);
}