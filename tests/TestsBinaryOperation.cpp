/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** TestsBinaryOperation
*/

#include "AComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(BinaryOperation_and, BinaryOperation, .init = redirect_all_std)
{
    nts::BinaryOperation op;
    cr_assert_eq(op.and_(nts::True, nts::True), nts::True);
    cr_assert_eq(op.and_(nts::True, nts::False), nts::False);
    cr_assert_eq(op.and_(nts::False, nts::True), nts::False);
    cr_assert_eq(op.and_(nts::False, nts::False), nts::False);
    cr_assert_eq(op.and_(nts::False, nts::Undefined), nts::False);
    cr_assert_eq(op.and_(nts::True, nts::Undefined), nts::Undefined);
    cr_assert_eq(op.and_(nts::Undefined, nts::False), nts::False);
    cr_assert_eq(op.and_(nts::Undefined, nts::True), nts::Undefined);
    cr_assert_eq(op.and_(nts::Undefined, nts::Undefined), nts::Undefined);
}

Test(BinaryOperation_nand, BinaryOperation, .init = redirect_all_std)
{
    nts::BinaryOperation op;
    cr_assert_eq(op.nand_(nts::True, nts::True), nts::False);
    cr_assert_eq(op.nand_(nts::True, nts::False), nts::True);
    cr_assert_eq(op.nand_(nts::False, nts::True), nts::True);
    cr_assert_eq(op.nand_(nts::False, nts::False), nts::True);
    cr_assert_eq(op.nand_(nts::False, nts::Undefined), nts::True);
    cr_assert_eq(op.nand_(nts::True, nts::Undefined), nts::Undefined);
    cr_assert_eq(op.nand_(nts::Undefined, nts::False), nts::True);
    cr_assert_eq(op.nand_(nts::Undefined, nts::True), nts::Undefined);
    cr_assert_eq(op.nand_(nts::Undefined, nts::Undefined), nts::Undefined);
}

Test(BinaryOperation_or, BinaryOperation, .init = redirect_all_std)
{
    nts::BinaryOperation op;
    cr_assert_eq(op.or_(nts::True, nts::True), nts::True);
    cr_assert_eq(op.or_(nts::True, nts::False), nts::True);
    cr_assert_eq(op.or_(nts::False, nts::True), nts::True);
    cr_assert_eq(op.or_(nts::False, nts::False), nts::False);
    cr_assert_eq(op.or_(nts::False, nts::Undefined), nts::Undefined);
    cr_assert_eq(op.or_(nts::True, nts::Undefined), nts::True);
    cr_assert_eq(op.or_(nts::Undefined, nts::False), nts::Undefined);
    cr_assert_eq(op.or_(nts::Undefined, nts::True), nts::True);
    cr_assert_eq(op.or_(nts::Undefined, nts::Undefined), nts::Undefined);
}

Test(BinaryOperation_nor, BinaryOperation, .init = redirect_all_std)
{
    nts::BinaryOperation op;
    cr_assert_eq(op.nor_(nts::True, nts::True), nts::False);
    cr_assert_eq(op.nor_(nts::True, nts::False), nts::False);
    cr_assert_eq(op.nor_(nts::False, nts::True), nts::False);
    cr_assert_eq(op.nor_(nts::False, nts::False), nts::True);
    cr_assert_eq(op.nor_(nts::False, nts::Undefined), nts::Undefined);
    cr_assert_eq(op.nor_(nts::True, nts::Undefined), nts::False);
    cr_assert_eq(op.nor_(nts::Undefined, nts::False), nts::Undefined);
    cr_assert_eq(op.nor_(nts::Undefined, nts::True), nts::False);
    cr_assert_eq(op.nor_(nts::Undefined, nts::Undefined), nts::Undefined);
}

Test(BinaryOperation_xor, BinaryOperation, .init = redirect_all_std)
{
    nts::BinaryOperation op;
    cr_assert_eq(op.xor_(nts::True, nts::True), nts::False);
    cr_assert_eq(op.xor_(nts::True, nts::False), nts::True);
    cr_assert_eq(op.xor_(nts::False, nts::True), nts::True);
    cr_assert_eq(op.xor_(nts::False, nts::False), nts::False);
    cr_assert_eq(op.xor_(nts::False, nts::Undefined), nts::Undefined);
    cr_assert_eq(op.xor_(nts::True, nts::Undefined), nts::Undefined);
    cr_assert_eq(op.xor_(nts::Undefined, nts::False), nts::Undefined);
    cr_assert_eq(op.xor_(nts::Undefined, nts::True), nts::Undefined);
    cr_assert_eq(op.xor_(nts::Undefined, nts::Undefined), nts::Undefined);
}
