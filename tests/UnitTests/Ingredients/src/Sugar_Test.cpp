#include "../include/Sugar_TestFixtures.hpp"

#include "BeverageDescription_TestHelpers.hpp"
#include "Domain/Beverages/Coffee.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include <string>

namespace coffee_shop::domain
{
TEST_F(GivenSomeSugar, WhenSugarIsAddedToCoffeeThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  const std::unique_ptr<IBeverage> beverage =
      std::make_unique<Sugar>(std::move(m_Coffee));

  // Act
  const std::string coffeeWithSugar(beverage->getDescription());

  // Assert
  ASSERT_EQ(
      coffeeWithSugar.compare(test_support::describe({CoffeeName, SugarName})),
      0);
}
} // namespace coffee_shop::domain
