#include "../include/IngredientFactory_TestFixtures.hpp"

#include "Domain/Beverages/Coffee.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Cream.hpp"
#include "Domain/Ingredients/Honey.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Lemon.hpp"
#include "Domain/Ingredients/Milk.hpp"
#include "Domain/Ingredients/SoyMilk.hpp"
#include "Domain/Ingredients/Sugar.hpp"
#include "Domain/Ingredients/Water.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <tuple>

namespace coffee_shop::domain
{
INSTANTIATE_TEST_SUITE_P(
    AllIngredients, GivenAnIngredient,
    ::testing::Values(std::make_tuple(Ingredient::Sugar, SugarName),
                      std::make_tuple(Ingredient::Milk, MilkName),
                      std::make_tuple(Ingredient::Cream, CreamName),
                      std::make_tuple(Ingredient::Honey, HoneyName),
                      std::make_tuple(Ingredient::Lemon, LemonName),
                      std::make_tuple(Ingredient::SoyMilk, SoyMilkName),
                      std::make_tuple(Ingredient::Water, WaterName)));

TEST_P(GivenAnIngredient, WhenItIsAddedToACoffeeThenTheDescriptionEndsWithIt)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  const auto [ingredient, ingredientName] = GetParam();

  // Act
  const std::unique_ptr<IBeverage> beverage =
      m_IngredientFactory.createIngredient(ingredient,
                                           std::make_unique<Coffee>());

  // Assert
  ASSERT_NE(beverage, nullptr);
  ASSERT_EQ(beverage->getDescription(),
            test_support::describe({CoffeeName, ingredientName}));
}
} // namespace coffee_shop::domain
