#include "../include/Coffee_TestFixtures.hpp"
#include <string>

namespace coffee_shop
{
TEST_F(GivenACoffee, WhenDescriptionIsRequiredThenAnswerHasRightFormat)
{
  // AAA
  ASSERT_EQ(m_Coffee->getDescription().compare(CoffeName), 0);
}
} // namespace coffee_shop