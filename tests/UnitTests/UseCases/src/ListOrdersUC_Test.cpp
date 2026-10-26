#include "../include/ListOrdersUC_TestFixtures.hpp"

#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Beverages/CoffeeLatte.hpp"
#include "Domain/Ingredients/Sugar.hpp"

#include <memory>
#include <string>
#include <vector>

namespace coffee_shop::application
{
TEST_F(GivenAnOrderRepository, WhenThereAreNoOrdersThenAnEmptyListIsSent)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ListOrdersUC listOrdersUC("ListOrdersUC", m_OrderRepository, m_OutputPort);

  // Act
  const bool success = listOrdersUC.execute();

  // Assert
  ASSERT_TRUE(success);
  ASSERT_TRUE(m_OutputPort.getListedDescriptions().has_value());
  ASSERT_TRUE(m_OutputPort.getListedDescriptions()->empty());
}

TEST_F(GivenAnOrderRepository, WhenThereAreOrdersThenTheyAreSentInOrder)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  m_OrderRepository.save(
      std::make_unique<domain::Sugar>(std::make_unique<domain::CoffeeLatte>()));
  m_OrderRepository.save(std::make_unique<domain::Cocoa>());
  ListOrdersUC listOrdersUC("ListOrdersUC", m_OrderRepository, m_OutputPort);

  // Act
  listOrdersUC.execute();

  // Assert
  ASSERT_EQ(m_OutputPort.getListedDescriptions(),
            (std::vector<std::string>{"CoffeeLatte, Sugar", "Cocoa"}));
}
} // namespace coffee_shop::application
