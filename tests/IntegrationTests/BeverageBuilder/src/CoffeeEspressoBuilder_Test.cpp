#include "../include/CoffeeEspressoBuilder_TestFixtures.hpp"

#include "Domain/Beverages/CoffeeEspresso.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Milk.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

namespace coffee_shop::domain
{
TEST_F(GivenACoffeeEspressoBuilder,
       WhenSugarIsAddedToCoffeeThenDescriptionHasRightFormat)

{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::vector<Ingredient> ingredients;
  ingredients.push_back(Ingredient::Sugar);

  // Act
  const bool built = m_BeverageBuildDirector->buildBeverage(ingredients);
  const std::string coffeeWithSugar =
      m_CoffeeEspressoBuilder->takeBeverage()->getDescription();

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(coffeeWithSugar.compare(
                test_support::describe({CoffeeEspressoName, SugarName})),
            0);
}

TEST_F(GivenACoffeeEspressoBuilder, WhenBeverageIsTakenThenBuilderIsReset)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_BeverageBuildDirector->buildBeverage({Ingredient::Sugar});
  m_CoffeeEspressoBuilder->takeBeverage();

  // Act
  const std::unique_ptr<IBeverage> secondBeverage =
      m_CoffeeEspressoBuilder->takeBeverage();

  // Assert
  ASSERT_NE(secondBeverage, nullptr);
  ASSERT_EQ(secondBeverage->getDescription(), CoffeeEspressoName);
}

TEST_F(GivenACoffeeEspressoBuilder, WhenASecondMilkIsAddedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_CoffeeEspressoBuilder->addMilk(Ingredient::Milk);

  // Act
  const bool creamAdded = m_CoffeeEspressoBuilder->addMilk(Ingredient::Cream);

  // Assert
  ASSERT_FALSE(creamAdded);
  ASSERT_EQ(m_CoffeeEspressoBuilder->takeBeverage()->getDescription(),
            test_support::describe({CoffeeEspressoName, MilkName}));
}

TEST_F(GivenACoffeeEspressoBuilder,
       WhenSomethingElseIsAddedAsMilkThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool added = m_CoffeeEspressoBuilder->addMilk(Ingredient::Sugar);

  // Assert
  ASSERT_FALSE(added);
  ASSERT_EQ(m_CoffeeEspressoBuilder->takeBeverage()->getDescription(),
            CoffeeEspressoName);
}

TEST_F(GivenACoffeeEspressoBuilder,
       WhenTheBeverageIsTakenThenMilkCanBeAddedAgain)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_CoffeeEspressoBuilder->addMilk(Ingredient::Milk);
  m_CoffeeEspressoBuilder->takeBeverage();

  // Act
  const bool milkAdded = m_CoffeeEspressoBuilder->addMilk(Ingredient::Milk);

  // Assert
  ASSERT_TRUE(milkAdded);
  ASSERT_EQ(m_CoffeeEspressoBuilder->takeBeverage()->getDescription(),
            test_support::describe({CoffeeEspressoName, MilkName}));
}
} // namespace coffee_shop::domain
