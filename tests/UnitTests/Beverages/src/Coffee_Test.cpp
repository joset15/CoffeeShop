#include "../include/Coffee_TestFixtures.hpp"

#include "Domain/Beverages/Coffee.hpp"
#include <string>

namespace coffee_shop::domain
{
TEST_F(GivenACoffee, WhenDescriptionIsRequiredThenAnswerHasRightFormat)
{
  // AAA
  ASSERT_EQ(m_Coffee->getDescription().compare(CoffeeName), 0);
}
} // namespace coffee_shop::domain
