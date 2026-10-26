#include "../include/CocoaBuilder_TestFixtures.hpp"

#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

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
} // namespace coffee_shop::domain
