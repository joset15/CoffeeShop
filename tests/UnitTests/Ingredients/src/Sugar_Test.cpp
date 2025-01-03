#include "../include/Sugar_TestFixtures.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include <string>

namespace CoffeeShop
{
TEST_F(GivenSomeSugar, WhenSugarIsAddedToCoffeeThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::shared_ptr<IBeverage> beverage = std::make_shared<Sugar>(m_Coffee);

  // Act
  std::string coffeeWithSugar(beverage->getDescription());

  // Assert
  ASSERT_EQ(coffeeWithSugar.compare(CoffeName + ", " + SugarName), 0);
}
} // namespace CoffeeShop