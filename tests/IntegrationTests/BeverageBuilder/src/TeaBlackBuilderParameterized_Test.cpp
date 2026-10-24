#include "../include/TeaBlackBuilderParameterized_TestFixtures.hpp"
#include <string>

namespace CoffeeShop
{

INSTANTIATE_TEST_CASE_P(
    GiveSomeValidIngredients, GivenSomeIngredientsForTeaBlackBuilder,
    ::testing::Values(
        // clang-format off
// Don't touch this!
   std::make_tuple(std::list<Ingredient>{Ingredient::Sugar}, true, TeaBlackName + ", " + SugarName),
   std::make_tuple(std::list<Ingredient>{Ingredient::Lemon}, true, TeaBlackName + ", " + LemonName),
   std::make_tuple(std::list<Ingredient>{Ingredient::Milk, Ingredient::Lemon}, false, TeaBlackName + ", " + MilkName)
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

} // namespace CoffeeShop