#include "../include/BeverageBuildDirector_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"

#include <string>

namespace coffee_shop::domain
{
TEST_F(GivenADirector, WhenCocoaWithMilkIsBuiltThenDescriptionHasMilk)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::Cocoa, {Ingredient::Milk});

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(m_Builder->takeBeverage()->getDescription(),
            test_support::describe({CocoaName, MilkName}));
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

TEST_F(GivenADirector, WhenLatteWithSugarIsBuiltThenDescriptionHasSugar)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::CoffeeLatte, {Ingredient::Sugar});

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(m_Builder->takeBeverage()->getDescription(),
            test_support::describe({CoffeeLatteName, SugarName}));
}

TEST_F(GivenADirector, WhenMilkIsAddedToLatteThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::CoffeeLatte, {Ingredient::SoyMilk});

  // Assert
  ASSERT_FALSE(built);
}

TEST_F(GivenADirector, WhenDecafWithSoyMilkIsBuiltThenDescriptionHasSoyMilk)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::CoffeeDecaf, {Ingredient::SoyMilk});

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(m_Builder->takeBeverage()->getDescription(),
            test_support::describe({CoffeeDecafName, SoyMilkName}));
}

TEST_F(GivenADirector, WhenDecafWithHoneyIsBuiltThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built = build(BeverageVariety::CoffeeDecaf, {Ingredient::Honey});

  // Assert
  ASSERT_FALSE(built);
}

TEST_F(GivenADirector,
       WhenGreenTeaWithHoneyAndLemonIsBuiltThenDescriptionHasBoth)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built =
      build(BeverageVariety::TeaGreen, {Ingredient::Lemon, Ingredient::Honey});

  // Assert
  ASSERT_TRUE(built);
  ASSERT_EQ(m_Builder->takeBeverage()->getDescription(),
            test_support::describe({TeaGreenName, HoneyName, LemonName}));
}

TEST_F(GivenADirector, WhenGreenTeaWithMilkAndLemonIsBuiltThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool built =
      build(BeverageVariety::TeaGreen, {Ingredient::Milk, Ingredient::Lemon});

  // Assert
  ASSERT_FALSE(built);
}
} // namespace coffee_shop::domain
