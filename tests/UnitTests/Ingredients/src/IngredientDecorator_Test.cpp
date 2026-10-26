#include "../include/IngredientDecorator_TestFixtures.hpp"

#include "BeverageDescription_TestHelpers.hpp"
#include "Domain/Beverages/Coffee.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Milk.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>
#include <utility>

namespace coffee_shop::domain
{
TEST_F(GivenANullBeverage, WhenDecoratedThenThrowsInvalidArgument)
{
  // AAA: Arrange, Act, Assert
  // Act & Assert
  EXPECT_THROW(Sugar{std::move(m_Beverage)}, std::invalid_argument);
}

TEST_F(GivenSugarAndMilk, WhenChainedThenDescriptionContainsBoth)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::unique_ptr<IBeverage> beverage =
      std::make_unique<Sugar>(std::move(m_Coffee));

  // Act
  beverage = std::make_unique<Milk>(std::move(beverage));

  // Assert
  ASSERT_EQ(beverage->getDescription(),
            test_support::describe({CoffeeName, SugarName, MilkName}));
}
} // namespace coffee_shop::domain
