#include "../include/OrderRepository_TestFixtures.hpp"

#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Beverages/CoffeeLatte.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

namespace coffee_shop::interface_adapters
{
TEST_F(GivenAnEmptyOrderRepository, WhenNothingIsSavedThenThereAreNoOrders)
{
  // AAA: Arrange, Act, Assert
  // Act
  const std::vector<std::string> descriptions =
      m_OrderRepository.describeOrders();

  // Assert
  ASSERT_TRUE(descriptions.empty());
}

TEST_F(GivenAnEmptyOrderRepository, WhenAnOrderIsSavedThenItIsAccepted)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool saved = m_OrderRepository.save(std::make_unique<domain::Cocoa>());

  // Assert
  ASSERT_TRUE(saved);
  ASSERT_EQ(
      m_OrderRepository.describeOrders(),
      std::vector<std::string>{test_support::describe({domain::CocoaName})});
}

TEST_F(GivenAnEmptyOrderRepository,
       WhenSeveralOrdersAreSavedThenTheyAreDescribedInOrder)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_OrderRepository.save(
      std::make_unique<domain::Sugar>(std::make_unique<domain::CoffeeLatte>()));
  m_OrderRepository.save(std::make_unique<domain::Cocoa>());

  // Act
  const std::vector<std::string> descriptions =
      m_OrderRepository.describeOrders();

  // Assert
  ASSERT_EQ(
      descriptions,
      (std::vector<std::string>{
          test_support::describe({domain::CoffeeLatteName, domain::SugarName}),
          test_support::describe({domain::CocoaName})}));
}
} // namespace coffee_shop::interface_adapters
