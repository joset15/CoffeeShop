#ifndef TEA_BLACK_BUILDER_SINGLE_TESTFIXTURES_HPP
#define TEA_BLACK_BUILDER_SINGLE_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"

#include "DomainFactories_TestHelpers.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::domain
{
///
/// \brief A fixture for calling a TeaBlackBuilder directly, without a
/// director (the director already rejects some combinations itself).
///
class GivenATeaBlackBuilder : public ::testing::Test
{
protected:
  test_support::DomainFactories m_Factories;
  TeaBlackBuilder m_TeaBlackBuilder{m_Factories.m_BeverageFactory,
                                    m_Factories.m_IngredientFactory};
};
} // namespace coffee_shop::domain

#endif // TEA_BLACK_BUILDER_SINGLE_TESTFIXTURES_HPP
