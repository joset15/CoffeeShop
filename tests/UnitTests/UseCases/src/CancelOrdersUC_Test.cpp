#include "../include/CancelOrdersUC_TestFixtures.hpp"

#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Beverages/CoffeeLatte.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <memory>

namespace coffee_shop::application
{
TEST_F(GivenACancelOrdersUseCase, WhenThereAreOrdersThenAllAreCancelled)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_OrderRepository.save(std::make_unique<domain::CoffeeLatte>());
  m_OrderRepository.save(std::make_unique<domain::Cocoa>());

  // Act
  const bool success = m_CancelOrdersUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OutputPort.getCancelledCount(), std::size_t{2});
  ASSERT_TRUE(m_OrderRepository.getSavedOrders().empty());
}

TEST_F(GivenACancelOrdersUseCase, WhenThereAreNoOrdersThenZeroIsReported)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool success = m_CancelOrdersUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OutputPort.getCancelledCount(), std::size_t{0});
}
} // namespace coffee_shop::application
