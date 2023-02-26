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

Test(SixInverterComponent_1, SixInverterComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> sixInverter_ = std::make_unique<nts::SixInverterComponent>();
    sixInverter_->setLink(1, *inputTrue, 1);
    cr_assert_eq(sixInverter_->compute(2), nts::False);
}

Test(SixInverterComponent_2, SixInverterComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> sixInverter_ = std::make_unique<nts::SixInverterComponent>();
    sixInverter_->setLink(3, *inputTrue, 1);
    cr_assert_eq(sixInverter_->compute(4), nts::False);
}

Test(SixInverterComponent_3, SixInverterComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::InputComponent>();
    std::unique_ptr<nts::IComponent> sixInverter_ = std::make_unique<nts::SixInverterComponent>();
    sixInverter_->setLink(5, *inputTrue, 1);
    cr_assert_eq(sixInverter_->compute(6), nts::Undefined);
}

Test(SixInverterComponent_4, SixInverterComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> sixInverter_ = std::make_unique<nts::SixInverterComponent>();
    sixInverter_->setLink(13, *inputTrue, 1);
    cr_assert_eq(sixInverter_->compute(12), nts::True);
}

Test(SixInverterComponent_5, SixInverterComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> sixInverter_ = std::make_unique<nts::SixInverterComponent>();
    sixInverter_->setLink(11, *inputTrue, 1);
    cr_assert_eq(sixInverter_->compute(10), nts::False);
}

Test(SixInverterComponent_6, SixInverterComponent, .init = redirect_all_std)
{
    std::unique_ptr<nts::IComponent> inputTrue = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> sixInverter_ = std::make_unique<nts::SixInverterComponent>();
    sixInverter_->setLink(9, *inputTrue, 1);
    cr_assert_eq(sixInverter_->compute(8), nts::False);
}
