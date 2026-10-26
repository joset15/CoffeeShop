#include "../include/CoffeeEspressoBuilderParameterized_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"
#include <string>

namespace coffee_shop::domain
{
INSTANTIATE_TEST_CASE_P(
    GiveSomeValidIngredients, GivenSomeIngredientsForCoffeeEspressoBuilder,
    ::testing::Values(
        // clang-format off
// Don't touch this!
   std::make_tuple(std::list<Ingredient>{Ingredient::Sugar}, true, test_support::describe({CoffeeEspressoName, SugarName})),
   std::make_tuple(std::list<Ingredient>{Ingredient::Lemon}, false, test_support::describe({CoffeeEspressoName}))
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
  bool buildSuccess = m_BeverageBuildDirector->buildBeverage(ingredients);
  EXPECT_EQ(buildSuccess, isValidMix);

  std::string coffeeWithSomeIngredients =
      m_CoffeeEspressoBuilder->takeBeverage()->getDescription();

  // Assert
  ASSERT_EQ(coffeeWithSomeIngredients.compare(beverageName), 0);
}

} // namespace coffee_shop::domain
