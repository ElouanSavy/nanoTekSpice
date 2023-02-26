/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsOr
*/

#include "AComponent.hpp"
#include "FalseComponent.hpp"
#include "FourNorComponent.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(FourNorComponent_True_True, FourNorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::FourNorComponent>();
    or_->setLink(1, *inputTrue, 1);
    or_->setLink(2, *inputTrue, 1);
    cr_assert_eq(or_->compute(3), nts::False);
}

Test(FourNorComponent_False_False, FourNorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::FourNorComponent>();
    or_->setLink(5, *inputFalse, 1);
    or_->setLink(6, *inputFalse, 1);
    cr_assert_eq(or_->compute(4), nts::True);
}

Test(FourNorComponent_True_False, FourNorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::FourNorComponent>();
    or_->setLink(12, *inputTrue, 1);
    or_->setLink(13, *inputFalse, 1);
    cr_assert_eq(or_->compute(11), nts::False);
}

Test(FourNorComponent_False_True, FourNorComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> or_ = std::make_unique<nts::FourNorComponent>();
    or_->setLink(8, *inputFalse, 1);
    or_->setLink(9, *inputTrue, 1);
    cr_assert_eq(or_->compute(10), nts::False);
}
