#include "../include/BeverageBuildDirectorParameterized_TestFixtures.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Beverages/CoffeeDecaf.hpp"
#include "Domain/Beverages/CoffeeEspresso.hpp"
#include "Domain/Beverages/CoffeeLatte.hpp"
#include "Domain/Beverages/TeaBlack.hpp"
#include "Domain/Beverages/TeaGreen.hpp"
#include "Domain/Ingredients/Cream.hpp"
#include "Domain/Ingredients/Honey.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Lemon.hpp"
#include "Domain/Ingredients/Milk.hpp"
#include "Domain/Ingredients/SoyMilk.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

// The rows follow the "Beverages and ingredient rules" table in AGENTS.md.
// Ingredients are always added in the same order: sugar, milk, honey, lemon,
// water.
namespace coffee_shop::domain
{
using test_support::describe;

INSTANTIATE_TEST_SUITE_P(
    RulesTable, GivenAnAcceptedOrder,
    ::testing::Values(
        // Coffee (espresso, decaf): sugar and one kind of milk.
        AcceptedOrder{"EspressoWithSugar",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Sugar},
                      describe({CoffeeEspressoName, SugarName})},
        AcceptedOrder{"EspressoWithMilk",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Milk},
                      describe({CoffeeEspressoName, MilkName})},
        // The same kind of milk twice is one kind: it is added only once.
        AcceptedOrder{"EspressoWithMilkTwice",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Milk, Ingredient::Milk},
                      describe({CoffeeEspressoName, MilkName})},
        AcceptedOrder{"EspressoWithCream",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Cream},
                      describe({CoffeeEspressoName, CreamName})},
        AcceptedOrder{"EspressoWithSoyMilk",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::SoyMilk},
                      describe({CoffeeEspressoName, SoyMilkName})},
        AcceptedOrder{"DecafWithSugarAndCream",
                      BeverageVariety::CoffeeDecaf,
                      {Ingredient::Cream, Ingredient::Sugar},
                      describe({CoffeeDecafName, SugarName, CreamName})},
        // Latte: only sugar (it already has milk).
        AcceptedOrder{"LatteWithSugar",
                      BeverageVariety::CoffeeLatte,
                      {Ingredient::Sugar},
                      describe({CoffeeLatteName, SugarName})},
        // Tea (black, green): sugar, one kind of milk, honey, lemon.
        AcceptedOrder{"BlackTeaWithSugarAndMilk",
                      BeverageVariety::TeaBlack,
                      {Ingredient::Milk, Ingredient::Sugar},
                      describe({TeaBlackName, SugarName, MilkName})},
        AcceptedOrder{"BlackTeaWithCreamAndHoney",
                      BeverageVariety::TeaBlack,
                      {Ingredient::Honey, Ingredient::Cream},
                      describe({TeaBlackName, CreamName, HoneyName})},
        AcceptedOrder{"GreenTeaWithSoyMilk",
                      BeverageVariety::TeaGreen,
                      {Ingredient::SoyMilk},
                      describe({TeaGreenName, SoyMilkName})},
        AcceptedOrder{"GreenTeaWithHoneyAndLemon",
                      BeverageVariety::TeaGreen,
                      {Ingredient::Lemon, Ingredient::Honey},
                      describe({TeaGreenName, HoneyName, LemonName})},
        // Cocoa: sugar, milk or soy milk, honey.
        AcceptedOrder{"CocoaWithSugarMilkAndHoney",
                      BeverageVariety::Cocoa,
                      {Ingredient::Honey, Ingredient::Milk, Ingredient::Sugar},
                      describe({CocoaName, SugarName, MilkName, HoneyName})},
        AcceptedOrder{"CocoaWithSoyMilk",
                      BeverageVariety::Cocoa,
                      {Ingredient::SoyMilk},
                      describe({CocoaName, SoyMilkName})}),
    OrderName{});

INSTANTIATE_TEST_SUITE_P(
    RulesTable, GivenARejectedOrder,
    ::testing::Values(
        // Coffee: no honey, lemon or water, and never two kinds of milk.
        RejectedOrder{"EspressoWithHoney",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Honey}},
        RejectedOrder{"EspressoWithLemon",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Lemon}},
        RejectedOrder{"DecafWithWater",
                      BeverageVariety::CoffeeDecaf,
                      {Ingredient::Water}},
        RejectedOrder{"EspressoWithMilkAndCream",
                      BeverageVariety::CoffeeEspresso,
                      {Ingredient::Milk, Ingredient::Cream}},
        // Latte: no milk of any kind.
        RejectedOrder{
            "LatteWithMilk", BeverageVariety::CoffeeLatte, {Ingredient::Milk}},
        RejectedOrder{"LatteWithCream",
                      BeverageVariety::CoffeeLatte,
                      {Ingredient::Cream}},
        // Tea: no water, and no milk together with lemon.
        RejectedOrder{"BlackTeaWithWater",
                      BeverageVariety::TeaBlack,
                      {Ingredient::Water}},
        RejectedOrder{"BlackTeaWithCreamAndLemon",
                      BeverageVariety::TeaBlack,
                      {Ingredient::Cream, Ingredient::Lemon}},
        RejectedOrder{"GreenTeaWithSoyMilkAndLemon",
                      BeverageVariety::TeaGreen,
                      {Ingredient::SoyMilk, Ingredient::Lemon}},
        // Cocoa: no cream, lemon or water, and never two kinds of milk.
        RejectedOrder{
            "CocoaWithCream", BeverageVariety::Cocoa, {Ingredient::Cream}},
        RejectedOrder{
            "CocoaWithWater", BeverageVariety::Cocoa, {Ingredient::Water}},
        RejectedOrder{"CocoaWithMilkAndSoyMilk",
                      BeverageVariety::Cocoa,
                      {Ingredient::Milk, Ingredient::SoyMilk}}),
    OrderName{});

TEST_P(GivenAnAcceptedOrder, WhenItIsBuiltThenItHasTheExpectedDescription)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool built = build();

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(m_Builder->takeBeverage()->getDescription(),
            GetParam().m_Description);
}

TEST_P(GivenARejectedOrder, WhenItIsBuiltThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool built = build();

  // Assert
  ASSERT_FALSE(built);
}
} // namespace coffee_shop::domain
