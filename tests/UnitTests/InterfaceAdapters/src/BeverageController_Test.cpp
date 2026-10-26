#include "../include/BeverageController_TestFixtures.hpp"

#include "Domain/Beverages/CoffeeEspresso.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include "BeverageDescription_TestHelpers.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace coffee_shop::interface_adapters
{
TEST_F(GivenABeverageController, WhenOrderIsValidThenOrderAddedIsReported)
{
  // AAA: Arrange, Act, Assert
  // Act
  m_BeverageController.addOrder(m_ValidRequest, m_AddNewOrderOutputPort);

  // Assert
  ASSERT_EQ(m_AddNewOrderOutputPort.getAddedDescriptions(),
            (std::vector<std::string>{test_support::describe(
                {domain::CoffeeEspressoName, domain::SugarName})}));
}

TEST_F(GivenABeverageController, WhenOrderIsInvalidThenRejectionIsReported)
{
  // AAA: Arrange, Act, Assert
  // Act
  m_BeverageController.addOrder(m_InvalidRequest, m_AddNewOrderOutputPort);

  // Assert
  ASSERT_EQ(m_AddNewOrderOutputPort.getRejectedCount(), 1);
}

TEST_F(GivenABeverageController, WhenOrdersAreListedThenTheAddedOrdersAreSent)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_BeverageController.addOrder(m_ValidRequest, m_AddNewOrderOutputPort);

  // Act
  m_BeverageController.listOrders(m_ListOrdersOutputPort);

  // Assert
  ASSERT_EQ(m_ListOrdersOutputPort.getListedDescriptions(),
            (std::vector<std::string>{test_support::describe(
                {domain::CoffeeEspressoName, domain::SugarName})}));
}
} // namespace coffee_shop::interface_adapters
