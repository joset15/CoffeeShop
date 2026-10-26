#include "../include/AddNewOrderUC_TestFixtures.hpp"
#include "BeverageDescription_TestHelpers.hpp"

#include <string>
#include <vector>

namespace coffee_shop::application
{
TEST_F(GivenAnEspressoWithSugarOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC(m_Request, m_OrderRepository, m_OutputPort);

  // Act
  const bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().size(), 1U);
  ASSERT_EQ(
      m_OrderRepository.getSavedOrders().front()->getDescription(),
      test_support::describe({domain::CoffeeEspressoName, domain::SugarName}));
}

TEST_F(GivenAnEspressoWithLemonOrder, WhenExecutedThenNothingIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC(m_Request, m_OrderRepository, m_OutputPort);

  // Act
  const bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_FALSE(success);
  ASSERT_TRUE(m_OrderRepository.getSavedOrders().empty());
}

TEST_F(GivenALatteOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC(m_Request, m_OrderRepository, m_OutputPort);

  // Act
  const bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().size(), 1U);
  ASSERT_EQ(
      m_OrderRepository.getSavedOrders().front()->getDescription(),
      test_support::describe({domain::CoffeeLatteName, domain::SugarName}));
}

TEST_F(GivenACocoaWithMilkOrder, WhenExecutedThenOrderIsSaved)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC(m_Request, m_OrderRepository, m_OutputPort);

  // Act
  const bool success = addNewOrderUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().size(), 1U);
  ASSERT_EQ(m_OrderRepository.getSavedOrders().front()->getDescription(),
            test_support::describe({domain::CocoaName, domain::MilkName}));
}

TEST_F(GivenAnEspressoWithSugarOrder, WhenExecutedThenOrderAddedIsReported)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC(m_Request, m_OrderRepository, m_OutputPort);

  // Act
  addNewOrderUC.execute();

  // Assert
  ASSERT_EQ(m_OutputPort.getAddedDescriptions(),
            (std::vector<std::string>{test_support::describe(
                {domain::CoffeeEspressoName, domain::SugarName})}));
  ASSERT_EQ(m_OutputPort.getRejectedCount(), 0);
}

TEST_F(GivenAnEspressoWithLemonOrder, WhenExecutedThenRejectionIsReported)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  AddNewOrderUC addNewOrderUC(m_Request, m_OrderRepository, m_OutputPort);

  // Act
  addNewOrderUC.execute();

  // Assert
  ASSERT_EQ(m_OutputPort.getRejectedCount(), 1);
  ASSERT_TRUE(m_OutputPort.getAddedDescriptions().empty());
}
} // namespace coffee_shop::application
