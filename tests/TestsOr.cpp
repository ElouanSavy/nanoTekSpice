/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsOr
*/

#include "AComponent.hpp"
#include "FalseComponent.hpp"
#include "OrComponent.hpp"
#include "InputComponent.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(OrComponent_True_True, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputTrue, 1);
    or_->setLink(2, *inputTrue, 1);
    cr_assert_eq(or_->compute(3), nts::True);
}

Test(OrComponent_False_False, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputFalse, 1);
    or_->setLink(2, *inputFalse, 1);
    cr_assert_eq(or_->compute(3), nts::False);
}

Test(OrComponent_True_False, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputTrue, 1);
    or_->setLink(2, *inputFalse, 1);
    cr_assert_eq(or_->compute(3), nts::True);
}

Test(OrComponent_False_True, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputFalse, 1);
    or_->setLink(2, *inputTrue, 1);
    cr_assert_eq(or_->compute(3), nts::True);
}

Test(OrComponent_False_Undefined, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputFalse, 1);
    or_->setLink(2, *inputUndefined, 1);
    cr_assert_eq(or_->compute(3), nts::Undefined);
}

Test(OrComponent_True_Undefined, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputTrue, 1);
    or_->setLink(2, *inputUndefined, 1);
    cr_assert_eq(or_->compute(3), nts::True);
}

Test(OrComponent_Undefined_False, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputUndefined, 1);
    or_->setLink(2, *inputFalse, 1);
    cr_assert_eq(or_->compute(3), nts::Undefined);
}

Test(OrComponent_Undefined_True, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputUndefined, 1);
    or_->setLink(2, *inputTrue, 1);
    cr_assert_eq(or_->compute(3), nts::True);
}

Test(OrComponent_Undefined_Undefined, OrComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> inputUndefined = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::OrComponent>();
    or_->setLink(1, *inputUndefined, 1);
    or_->setLink(2, *inputUndefined, 1);
    cr_assert_eq(or_->compute(3), nts::Undefined);
}
