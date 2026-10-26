#include "../include/CoffeeEspressoBuilder_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"
#include <string>

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

} // namespace coffee_shop::domain
