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
  m_BeverageBuildDirector->buildCoffee(ingredients);
  // TODO: EXPECT_TRUE(buildSuccess);

  std::string coffeeWithSomeIngredients =
      m_CoffeeEspressoBuilder->getBeverage()->getDescription();

  // Assert
  ASSERT_EQ(coffeeWithSomeIngredients.compare(beverageName), 0);
};

// Since, release 1.10 INSTANTIATE_TEST_CASE_P is replaced with
// INSTANTIATE_TEST_SUITE_P!
/*
INSTANTIATE_TEST_CASE_P(GiveSomeInvalidIngredients,
                        GivenSomeIngredientsForCoffeeEspressoBuilder,
                        ::testing::Values(std::list<Ingredient>{
                            Ingredient::Lemon}));
                            */
/*
TEST_P(GivenSomeIngredientsForCoffeeEspressoBuilder,
       WhenInvalidIngredientsAreAddedToCoffeeThenDescriptionHasRightFormat)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  std::list<Ingredient> ingredients = GetParam();

  // Act
  m_BeverageBuildDirector->buildCoffee(ingredients);
  // TODO: EXPECT_TRUE(buildSuccess);

  std::string coffeeWithSomeInvalidIngredients =
      m_CoffeeEspressoBuilder->getBeverage()->getDescription();

  // Assert
  /*
  ASSERT_EQ(coffeeWithSomeInvalidIngredients.compare(CoffeEspressoName + ", " +
                                                     SugarName),
            0);
            */
/*
  ASSERT_EQ(1, 1);
}*/

} // namespace CoffeeShop