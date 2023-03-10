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

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(AndComponent_True_True, AndComponent, .init = redirect_all_std) //* Inverser les paramètres
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputTrue, 1);
    and_->setLink(2, *inputTrue, 1);
    cr_assert_eq(and_->compute(3), nts::True);
}

Test(AndComponent_False_False, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputFalse, 1);
    and_->setLink(2, *inputFalse, 1);
    cr_assert_eq(and_->compute(3), nts::False);
}

Test(AndComponent_True_False, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputTrue, 1);
    and_->setLink(2, *inputFalse, 1);
    cr_assert_eq(and_->compute(3), nts::False);
}

Test(AndComponent_False_True, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputFalse, 1);
    and_->setLink(2, *inputTrue, 1);
    cr_assert_eq(and_->compute(3), nts::False);
}

Test(AndComponent_False_Undefined, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputFalse, 1);
    and_->setLink(2, *inputUndefined, 1);
    cr_assert_eq(and_->compute(3), nts::False);
}

Test(AndComponent_True_Undefined, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputTrue, 1);
    and_->setLink(2, *inputUndefined, 1);
    cr_assert_eq(and_->compute(3), nts::Undefined);
}

Test(AndComponent_Undefined_False, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputUndefined, 1);
    and_->setLink(2, *inputFalse, 1);
    cr_assert_eq(and_->compute(3), nts::False);
}

Test(AndComponent_Undefined_True, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputUndefined, 1);
    and_->setLink(2, *inputTrue, 1);
    cr_assert_eq(and_->compute(3), nts::Undefined);
}

Test(AndComponent_Undefined_Undefined, AndComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::AndComponent>();
    and_->setLink(1, *inputUndefined, 1);
    and_->setLink(2, *inputUndefined, 1);
    cr_assert_eq(and_->compute(3), nts::Undefined);
}
