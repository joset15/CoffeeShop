#include "../include/AddNewOrderUC_TestFixtures.hpp"

#include <string>

namespace CoffeeShop
{
TEST_F(GivenAnEspressoWithSugarOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository);

  // Act
  bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().size(), 1U);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().front()->getDescription(),
            CoffeEspressoName + ", " + SugarName);
}

TEST_F(GivenAnEspressoWithLemonOrder, WhenExecutedThenNothingIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository);

  // Act
  bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_FALSE(success);
  ASSERT_TRUE(m_OrderRepository.getSavedOrders().empty());
}
} // namespace CoffeeShop
