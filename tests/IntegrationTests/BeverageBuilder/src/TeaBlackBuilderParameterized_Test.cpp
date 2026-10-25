#include "../include/TeaBlackBuilderParameterized_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"
#include <string>

namespace coffee_shop
{

INSTANTIATE_TEST_CASE_P(
    GiveSomeValidIngredients, GivenSomeIngredientsForTeaBlackBuilder,
    ::testing::Values(
        // clang-format off
// Don't touch this!
   std::make_tuple(std::list<Ingredient>{Ingredient::Sugar}, true, describe({TeaBlackName, SugarName})),
   std::make_tuple(std::list<Ingredient>{Ingredient::Lemon}, true, describe({TeaBlackName, LemonName})),
   std::make_tuple(std::list<Ingredient>{Ingredient::Milk, Ingredient::Lemon}, false, describe({TeaBlackName, MilkName}))
   ));
// clang-format on
// Carry on formatting

TEST_P(GivenSomeIngredientsForTeaBlackBuilder,
       WhenValidIngredientsAreAddedToTeaBlackThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::list<Ingredient> ingredients = std::get<0>(GetParam());
  bool isValidMix = std::get<1>(GetParam());
  std::string beverageName = std::get<2>(GetParam());

  // Act
  bool buildSuccess = m_BeverageBuildDirector->buildTeaBlack(ingredients);
  EXPECT_EQ(buildSuccess, isValidMix);

  std::string teaWithSomeIngredients =
      m_TeaBlackBuilder->takeBeverage()->getDescription();

  // Assert
  ASSERT_EQ(teaWithSomeIngredients.compare(beverageName), 0);
}

} // namespace coffee_shop