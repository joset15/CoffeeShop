#ifndef INGREDIENT_DECORATOR_TESTFIXTURES_HPP
#define INGREDIENT_DECORATOR_TESTFIXTURES_HPP

#include "Domain/Beverages/Coffee.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace coffee_shop::domain
{
///
/// \brief A fixture for decorating a beverage that does not exist.
///
class GivenANullBeverage : public ::testing::Test
{
protected:
  std::unique_ptr<IBeverage> m_Beverage;
};

///
/// \brief A fixture for decorating a coffee with sugar and milk.
///
class GivenSugarAndMilk : public ::testing::Test
{
protected:
  void SetUp() override { m_Coffee = std::make_unique<Coffee>(); }

  std::unique_ptr<IBeverage> m_Coffee;
};
} // namespace coffee_shop::domain

#endif // INGREDIENT_DECORATOR_TESTFIXTURES_HPP
