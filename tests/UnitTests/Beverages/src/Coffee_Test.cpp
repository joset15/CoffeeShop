#include "../include/Coffee_TestFixtures.hpp"
#include <string>

namespace CoffeeShop
{
TEST_F(GivenACoffee, WhenDescriptionIsRequiredThenAnswerHasRightFormat)
{
  // AAA
  ASSERT_EQ(m_Coffee->getDescription().compare(CoffeName), 0);
}
} // namespace CoffeeShop