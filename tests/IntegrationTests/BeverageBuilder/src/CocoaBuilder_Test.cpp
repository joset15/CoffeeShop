#include "../include/CocoaBuilder_TestFixtures.hpp"

#include <string>

namespace CoffeeShop
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
} // namespace CoffeeShop
