#include "../include/BeverageBuilderSimpleFactory_TestFixtures.hpp"

#include <memory>

namespace coffee_shop::domain
{
INSTANTIATE_TEST_CASE_P(
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
  const std::shared_ptr<IBeverageBuilder> builder =
      BeverageBuilderSimpleFactory::getInstance()->createBeverageBuilder(
          beverageVariety);

  // Assert
  ASSERT_NE(builder, nullptr);
  ASSERT_EQ(builder->takeBeverage()->getDescription(), beverageName);
}
} // namespace coffee_shop::domain
