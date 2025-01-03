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
      m_CoffeeEspressoBuilder->getBeverage()->getDescription();

  // Assert
  ASSERT_EQ(coffeeWithSugar.compare(CoffeEspressoName + ", " + SugarName), 0);
}

} // namespace CoffeeShop