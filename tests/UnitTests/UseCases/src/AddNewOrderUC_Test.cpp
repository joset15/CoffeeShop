#include "../include/AddNewOrderUC_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"

#include <string>

namespace coffee_shop
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
            describe({CoffeeEspressoName, SugarName}));
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

TEST_F(GivenALatteOrder, WhenExecutedThenNothingIsSaved)
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

TEST_F(GivenACocoaWithMilkOrder, WhenExecutedThenOrderIsSaved)
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
            describe({CocoaName, MilkName}));
}
} // namespace coffee_shop
