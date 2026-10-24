#include "../include/BeverageController_TestFixtures.hpp"

#include <string>

namespace CoffeeShop
{
TEST_F(GivenABeverageController, WhenOrderIsValidThenResponseIsSuccess)
{
  // AAA: Arrange, Act, Assert
  // Act
  AddNewOrderResponseMessage response =
      m_BeverageController.execAddOrderUC(m_ValidRequest);

  // Assert
  ASSERT_TRUE(response.getSuccess());
  ASSERT_EQ(response.getMessage(),
            std::string(BeverageController::OrderAddedMessage));
}

TEST_F(GivenABeverageController, WhenOrderIsInvalidThenResponseIsFailure)
{
  // AAA: Arrange, Act, Assert
  // Act
  AddNewOrderResponseMessage response =
      m_BeverageController.execAddOrderUC(m_InvalidRequest);

  // Assert
  ASSERT_FALSE(response.getSuccess());
  ASSERT_EQ(response.getMessage(),
            std::string(BeverageController::OrderNotAddedMessage));
}
} // namespace CoffeeShop
