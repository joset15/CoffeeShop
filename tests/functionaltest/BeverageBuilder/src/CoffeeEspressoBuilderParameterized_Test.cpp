#include "pch.h"

#include "../include/CoffeeEspressoBuilderParameterized_TestFixtures.hpp"
#include <string>

namespace CoffeeShop
{

INSTANTIATE_TEST_CASE_P(
    GiveSomeValidIngredients, GivenSomeIngredientsForCoffeeEspressoBuilder,
    ::testing::Values(
        // clang-format off
// Don't touch this!
   std::make_tuple(std::list<Ingredient>{Ingredient::Sugar}, true, CoffeEspressoName + ", " + SugarName),
   std::make_tuple(std::list<Ingredient>{Ingredient::Lemon}, false, CoffeEspressoName)
   ));
// clang-format on
// Carry on formatting

TEST_P(GivenSomeIngredientsForCoffeeEspressoBuilder,
       WhenValidIngredientsAreAddedToCoffeeThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::list<Ingredient> ingredients = std::get<0>(GetParam());
  bool isValidMix = std::get<1>(GetParam());
  std::string beverageName = std::get<2>(GetParam());

  // Act
  bool buildSuccess = m_BeverageBuildDirector->buildCoffeeEspresso(ingredients);
  EXPECT_EQ(buildSuccess, isValidMix);

  std::string coffeeWithSomeIngredients =
      m_CoffeeEspressoBuilder->getBeverage()->getDescription();

  // Assert
  ASSERT_EQ(coffeeWithSomeIngredients.compare(beverageName), 0);
}

} // namespace CoffeeShop