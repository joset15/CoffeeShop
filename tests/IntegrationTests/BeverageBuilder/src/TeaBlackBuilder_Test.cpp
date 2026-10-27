#include "../include/TeaBlackBuilder_TestFixtures.hpp"

#include "Domain/Beverages/TeaBlack.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Lemon.hpp"
#include "Domain/Ingredients/Milk.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::domain
{
TEST_F(GivenATeaBlackBuilder, WhenMilkIsAddedAfterLemonThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_TeaBlackBuilder.addLemon();

  // Act
  const bool milkAdded = m_TeaBlackBuilder.addMilk(Ingredient::Milk);

  // Assert
  ASSERT_FALSE(milkAdded);
  ASSERT_EQ(m_TeaBlackBuilder.takeBeverage()->getDescription(),
            test_support::describe({TeaBlackName, LemonName}));
}

TEST_F(GivenATeaBlackBuilder, WhenASecondMilkIsAddedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_TeaBlackBuilder.addMilk(Ingredient::Milk);

  // Act
  const bool creamAdded = m_TeaBlackBuilder.addMilk(Ingredient::Cream);

  // Assert
  ASSERT_FALSE(creamAdded);
  ASSERT_EQ(m_TeaBlackBuilder.takeBeverage()->getDescription(),
            test_support::describe({TeaBlackName, MilkName}));
}

TEST_F(GivenATeaBlackBuilder, WhenSomethingElseIsAddedAsMilkThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool added = m_TeaBlackBuilder.addMilk(Ingredient::Honey);

  // Assert
  ASSERT_FALSE(added);
  ASSERT_EQ(m_TeaBlackBuilder.takeBeverage()->getDescription(), TeaBlackName);
}

TEST_F(GivenATeaBlackBuilder, WhenTheBeverageIsTakenThenMilkCanBeAddedAgain)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_TeaBlackBuilder.addLemon();
  m_TeaBlackBuilder.takeBeverage();

  // Act
  const bool milkAdded = m_TeaBlackBuilder.addMilk(Ingredient::Milk);

  // Assert
  ASSERT_TRUE(milkAdded);
  ASSERT_EQ(m_TeaBlackBuilder.takeBeverage()->getDescription(),
            test_support::describe({TeaBlackName, MilkName}));
}
} // namespace coffee_shop::domain
