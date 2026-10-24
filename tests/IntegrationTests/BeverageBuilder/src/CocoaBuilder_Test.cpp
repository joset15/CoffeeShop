#include "../include/CocoaBuilder_TestFixtures.hpp"

#include <string>

namespace coffee_shop
{
TEST_F(GivenACocoaBuilder, WhenCreamIsAddedThenItIsRejected)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool creamAdded = m_CocoaBuilder->addMilk(Ingredient::Cream);

  // Assert
  ASSERT_FALSE(creamAdded);
  ASSERT_EQ(m_CocoaBuilder->takeBeverage()->getDescription(), CocoaName);
}
} // namespace coffee_shop
