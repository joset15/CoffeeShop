#include "../include/BeverageBuildDirector_TestFixtures.hpp"

#include <string>

namespace coffee_shop
{
TEST_F(GivenADirector, WhenCocoaWithMilkIsBuiltThenDescriptionHasMilk)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::Cocoa, {Ingredient::Milk});

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(m_Builder->takeBeverage()->getDescription(),
            CocoaName + ", " + MilkName);
}

TEST_F(GivenADirector, WhenCocoaWithLemonIsBuiltThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::Cocoa, {Ingredient::Lemon});

  // Assert
  ASSERT_FALSE(built);
}

TEST_F(GivenADirector, WhenWaterIsRequestedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::CoffeeEspresso, {Ingredient::Water});

  // Assert
  ASSERT_FALSE(built);
}

TEST_F(GivenADirector, WhenTwoKindsOfMilkAreRequestedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built =
      build(BeverageVariety::TeaBlack, {Ingredient::Milk, Ingredient::SoyMilk});

  // Assert
  ASSERT_FALSE(built);
}
} // namespace coffee_shop
