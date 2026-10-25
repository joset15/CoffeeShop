#include "../include/AddNewOrderUC_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"

#include <string>
#include <vector>

namespace coffee_shop
{
TEST_F(GivenAnEspressoWithSugarOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository,
                              m_OutputPort);

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
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository,
                              m_OutputPort);

  // Act
  bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_FALSE(success);
  ASSERT_TRUE(m_OrderRepository.getSavedOrders().empty());
}

TEST_F(GivenALatteOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository,
                              m_OutputPort);

  // Act
  bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().size(), 1U);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().front()->getDescription(),
            describe({CoffeeLatteName, SugarName}));
}

TEST_F(GivenACocoaWithMilkOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository,
                              m_OutputPort);

  // Act
  bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().size(), 1U);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().front()->getDescription(),
            describe({CocoaName, MilkName}));
}

TEST_F(GivenAnEspressoWithSugarOrder, WhenExecutedThenOrderAddedIsReported)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository,
                              m_OutputPort);

  // Act
  addNewOrderUC.execute();

  // Assert
  ASSERT_EQ(
      m_OutputPort.getAddedDescriptions(),
      (std::vector<std::string>{describe({CoffeeEspressoName, SugarName})}));
  ASSERT_EQ(m_OutputPort.getRejectedCount(), 0);
}

TEST_F(GivenAnEspressoWithLemonOrder, WhenExecutedThenRejectionIsReported)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", m_Request, m_OrderRepository,
                              m_OutputPort);

  // Act
  addNewOrderUC.execute();

  // Assert
  ASSERT_EQ(m_OutputPort.getRejectedCount(), 1);
  ASSERT_TRUE(m_OutputPort.getAddedDescriptions().empty());
}
} // namespace coffee_shop
