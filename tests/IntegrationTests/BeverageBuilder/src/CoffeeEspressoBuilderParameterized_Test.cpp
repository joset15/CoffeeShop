#include "../include/CoffeeEspressoBuilderParameterized_TestFixtures.hpp"

#include "Domain/Beverages/CoffeeEspresso.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace coffee_shop::domain
{
INSTANTIATE_TEST_CASE_P(
    GiveSomeValidIngredients, GivenSomeIngredientsForCoffeeEspressoBuilder,
    ::testing::Values(
        // clang-format off
// Don't touch this!
   std::make_tuple(std::vector<Ingredient>{Ingredient::Sugar}, true, test_support::describe({CoffeeEspressoName, SugarName})),
   std::make_tuple(std::vector<Ingredient>{Ingredient::Lemon}, false, test_support::describe({CoffeeEspressoName}))
   ));
// clang-format on
// Carry on formatting

TEST_P(GivenSomeIngredientsForCoffeeEspressoBuilder,
       WhenValidIngredientsAreAddedToCoffeeThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  const std::vector<Ingredient> ingredients = std::get<0>(GetParam());
  const bool isValidMix = std::get<1>(GetParam());
  const std::string beverageName = std::get<2>(GetParam());

  // Act
  const bool buildSuccess = m_BeverageBuildDirector->buildBeverage(ingredients);
  EXPECT_EQ(buildSuccess, isValidMix);

  const std::string coffeeWithSomeIngredients =
      m_CoffeeEspressoBuilder->takeBeverage()->getDescription();

  // Assert
  ASSERT_EQ(coffeeWithSomeIngredients.compare(beverageName), 0);
}

} // namespace coffee_shop::domain
