/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsXor
*/

#include "AComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "XorComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(XorComponent_True_True, XorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::XorComponent>();
    xor_->setLink(1, *inputTrue, 1);
    xor_->setLink(2, *inputTrue, 1);
    cr_assert_eq(xor_->compute(3), nts::False);
}

Test(XorComponent_False_False, XorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::XorComponent>();
    xor_->setLink(1, *inputFalse, 1);
    xor_->setLink(2, *inputFalse, 1);
    cr_assert_eq(xor_->compute(3), nts::False);
}

Test(XorComponent_True_False, XorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::XorComponent>();
    xor_->setLink(1, *inputTrue, 1);
    xor_->setLink(2, *inputFalse, 1);
    cr_assert_eq(xor_->compute(3), nts::True);
}

Test(XorComponent_False_True, XorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::XorComponent>();
    xor_->setLink(1, *inputFalse, 1);
    xor_->setLink(2, *inputTrue, 1);
    cr_assert_eq(xor_->compute(3), nts::True);
}
