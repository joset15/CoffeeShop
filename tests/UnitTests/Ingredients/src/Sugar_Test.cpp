#include "../include/Sugar_TestFixtures.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include <string>

namespace coffee_shop
{
TEST_F(GivenSomeSugar, WhenSugarIsAddedToCoffeeThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::unique_ptr<IBeverage> beverage =
      std::make_unique<Sugar>(std::move(m_Coffee));

  // Act
  std::string coffeeWithSugar(beverage->getDescription());

  // Assert
  ASSERT_EQ(coffeeWithSugar.compare(CoffeName + ", " + SugarName), 0);
}
} // namespace coffee_shop