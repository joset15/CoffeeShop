#include "../include/TeaBlackBuilderParameterized_TestFixtures.hpp"

#include "BeverageDescription_TestHelpers.hpp"
#include "Domain/Beverages/TeaBlack.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Lemon.hpp"
#include "Domain/Ingredients/Milk.hpp"
#include "Domain/Ingredients/Sugar.hpp"
#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <vector>

namespace coffee_shop::domain
{
INSTANTIATE_TEST_CASE_P(
    GiveSomeValidIngredients, GivenSomeIngredientsForTeaBlackBuilder,
    ::testing::Values(
        // clang-format off
// Don't touch this!
   std::make_tuple(std::vector<Ingredient>{Ingredient::Sugar}, true, test_support::describe({TeaBlackName, SugarName})),
   std::make_tuple(std::vector<Ingredient>{Ingredient::Lemon}, true, test_support::describe({TeaBlackName, LemonName})),
   std::make_tuple(std::vector<Ingredient>{Ingredient::Milk, Ingredient::Lemon}, false, test_support::describe({TeaBlackName, MilkName}))
   ));
// clang-format on
// Carry on formatting

TEST_P(GivenSomeIngredientsForTeaBlackBuilder,
       WhenValidIngredientsAreAddedToTeaBlackThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  const std::vector<Ingredient> ingredients = std::get<0>(GetParam());
  const bool isValidMix = std::get<1>(GetParam());
  const std::string beverageName = std::get<2>(GetParam());

  // Act
  const bool buildSuccess = m_BeverageBuildDirector->buildBeverage(ingredients);
  EXPECT_EQ(buildSuccess, isValidMix);

  const std::string teaWithSomeIngredients =
      m_TeaBlackBuilder->takeBeverage()->getDescription();

  // Assert
  ASSERT_EQ(teaWithSomeIngredients.compare(beverageName), 0);
}

} // namespace coffee_shop::domain
