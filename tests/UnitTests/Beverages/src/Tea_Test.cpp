#include "../include/Tea_TestFixtures.hpp"

#include "Domain/Beverages/Tea.hpp"

#include <gtest/gtest.h>

#include <string>

namespace coffee_shop::domain
{
TEST_F(GivenATea, WhenDescriptionIsRequiredThenItIsTheTeaName)
{
  // AAA: Arrange, Act, Assert
  // Act
  const std::string description = m_Tea.getDescription();

  // Assert
  ASSERT_EQ(description, TeaName);
}
} // namespace coffee_shop::domain
