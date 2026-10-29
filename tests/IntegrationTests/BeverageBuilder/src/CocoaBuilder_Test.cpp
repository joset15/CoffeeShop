#include "../include/CocoaBuilder_TestFixtures.hpp"

#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Milk.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::domain
{
TEST_F(GivenACocoaBuilder, WhenCreamIsAddedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool creamAdded = m_CocoaBuilder->addMilk(Ingredient::Cream);

  // Assert
  ASSERT_FALSE(creamAdded);
  ASSERT_EQ(m_CocoaBuilder->takeBeverage()->getDescription(), CocoaName);
}

TEST_F(GivenACocoaBuilder, WhenASecondMilkIsAddedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_CocoaBuilder->addMilk(Ingredient::Milk);

  // Act
  const bool soyMilkAdded = m_CocoaBuilder->addMilk(Ingredient::SoyMilk);

  // Assert
  ASSERT_FALSE(soyMilkAdded);
  ASSERT_EQ(m_CocoaBuilder->takeBeverage()->getDescription(),
            test_support::describe({CocoaName, MilkName}));
}

TEST_F(GivenACocoaBuilder, WhenTheBeverageIsTakenThenMilkCanBeAddedAgain)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_CocoaBuilder->addMilk(Ingredient::Milk);
  m_CocoaBuilder->takeBeverage();

  // Act
  const bool milkAdded = m_CocoaBuilder->addMilk(Ingredient::Milk);

  // Assert
  ASSERT_TRUE(milkAdded);
  ASSERT_EQ(m_CocoaBuilder->takeBeverage()->getDescription(),
            test_support::describe({CocoaName, MilkName}));
}
} // namespace coffee_shop::domain
