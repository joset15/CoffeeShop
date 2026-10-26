#include "../include/BeverageBuilderSimpleFactory_TestFixtures.hpp"

#include "Domain/BeverageBuilder/IBeverageBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Beverages/CoffeeDecaf.hpp"
#include "Domain/Beverages/CoffeeEspresso.hpp"
#include "Domain/Beverages/CoffeeLatte.hpp"
#include "Domain/Beverages/TeaBlack.hpp"
#include "Domain/Beverages/TeaGreen.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <tuple>

namespace coffee_shop::domain
{
INSTANTIATE_TEST_SUITE_P(
    AllVarieties, GivenABeverageVariety,
    ::testing::Values(
        std::make_tuple(BeverageVariety::CoffeeEspresso, CoffeeEspressoName),
        std::make_tuple(BeverageVariety::CoffeeLatte, CoffeeLatteName),
        std::make_tuple(BeverageVariety::CoffeeDecaf, CoffeeDecafName),
        std::make_tuple(BeverageVariety::TeaBlack, TeaBlackName),
        std::make_tuple(BeverageVariety::TeaGreen, TeaGreenName),
        std::make_tuple(BeverageVariety::Cocoa, CocoaName)));

TEST_P(GivenABeverageVariety, WhenBuilderIsCreatedThenItBuildsThatBeverage)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  const auto [beverageVariety, beverageName] = GetParam();

  // Act
  const std::unique_ptr<IBeverageBuilder> builder =
      m_Factories.m_BuilderFactory.createBeverageBuilder(beverageVariety);

  // Assert
  ASSERT_NE(builder, nullptr);
  ASSERT_EQ(builder->takeBeverage()->getDescription(), beverageName);
}
} // namespace coffee_shop::domain
