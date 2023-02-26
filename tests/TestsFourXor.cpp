/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsXor
*/

#include "AComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "FourXorComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(FourXorComponent_True_True, FourXorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::FourXorComponent>();
    xor_->setLink(1, *inputTrue, 1);
    xor_->setLink(2, *inputTrue, 1);
    cr_assert_eq(xor_->compute(3), nts::False);
}

Test(FourXorComponent_False_False, FourXorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::FourXorComponent>();
    xor_->setLink(5, *inputFalse, 1);
    xor_->setLink(6, *inputFalse, 1);
    cr_assert_eq(xor_->compute(4), nts::False);
}

Test(FourXorComponent_True_False, FourXorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::FourXorComponent>();
    xor_->setLink(12, *inputTrue, 1);
    xor_->setLink(13, *inputFalse, 1);
    cr_assert_eq(xor_->compute(11), nts::True);
}

Test(FourXorComponent_False_True, FourXorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> xor_ = std::make_unique<nts::FourXorComponent>();
    xor_->setLink(8, *inputFalse, 1);
    xor_->setLink(9, *inputTrue, 1);
    cr_assert_eq(xor_->compute(10), nts::True);
}
