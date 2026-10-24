#include "../include/CoffeeEspressoBuilder_TestFixtures.hpp"
#include <string>

namespace CoffeeShop
{
TEST_F(GivenACoffeeEspressoBuilder,
       WhenSugarIsAddedToCoffeeThenDescriptionHasRightFormat)

{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::list<Ingredient> ingredients;
  ingredients.push_back(Ingredient::Sugar);

  // Act
  m_BeverageBuildDirector->buildCoffeeEspresso(ingredients);
  // TODO: EXPECT_TRUE(buildSuccess);

  std::string coffeeWithSugar =
      m_CoffeeEspressoBuilder->takeBeverage()->getDescription();

  // Assert
  ASSERT_EQ(coffeeWithSugar.compare(CoffeEspressoName + ", " + SugarName), 0);
}

TEST_F(GivenACoffeeEspressoBuilder, WhenBeverageIsTakenThenBuilderIsReset)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_BeverageBuildDirector->buildCoffeeEspresso({Ingredient::Sugar});
  m_CoffeeEspressoBuilder->takeBeverage();

  // Act
  std::unique_ptr<IBeverage> secondBeverage =
      m_CoffeeEspressoBuilder->takeBeverage();

  // Assert
  ASSERT_NE(secondBeverage, nullptr);
  ASSERT_EQ(secondBeverage->getDescription(), CoffeEspressoName);
}

} // namespace CoffeeShop