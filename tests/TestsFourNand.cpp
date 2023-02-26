/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGD09-elouan.savy-camaret
** File description:
** tests
*/

#include "AComponent.hpp"
#include "AndComponent.hpp"
#include "FalseComponent.hpp"
#include "FourBitAdderComponent.hpp"
#include "FourNandComponent.hpp"
#include "FourXorComponent.hpp"
#include "NotComponent.hpp"
#include "OrComponent.hpp"
#include "SixInverterComponent.hpp"
#include "TrueComponent.hpp"
#include "XorComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(FourNandComponent_True_True, FourNandComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::FourNandComponent>();
    and_->setLink(5, *inputTrue, 1);
    and_->setLink(6, *inputTrue, 1);
    cr_assert_eq(and_->compute(4), nts::False);
}

Test(FourNandComponent_False_False, FourNandComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::FourNandComponent>();
    and_->setLink(1, *inputFalse, 1);
    and_->setLink(2, *inputFalse, 1);
    cr_assert_eq(and_->compute(3), nts::True);
}

Test(FourNandComponent_True_False, FourNandComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::FourNandComponent>();
    and_->setLink(12, *inputTrue, 1);
    and_->setLink(13, *inputFalse, 1);
    cr_assert_eq(and_->compute(11), nts::True);
}

Test(FourNandComponent_False_True, FourNandComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inputFalse = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> and_ = std::make_unique<nts::FourNandComponent>();
    and_->setLink(8, *inputFalse, 1);
    and_->setLink(9, *inputTrue, 1);
    cr_assert_eq(and_->compute(10), nts::True);
}
