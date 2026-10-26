#include "../include/TextPresenter_TestFixtures.hpp"

#include <gtest/gtest.h>

#include <vector>

namespace coffee_shop::interface_adapters
{
TEST_F(GivenATextPresenter, WhenOrderIsAddedThenItsDescriptionIsWritten)
{
  // AAA: Arrange, Act, Assert
  // Act
  m_Presenter.orderAdded("CoffeeLatte, Sugar");

  // Assert
  ASSERT_EQ(m_Output.str(), "Info: Order added: CoffeeLatte, Sugar.\n");
}

TEST_F(GivenATextPresenter, WhenOrderIsRejectedThenAnErrorIsWritten)
{
  // AAA: Arrange, Act, Assert
  // Act
  m_Presenter.orderRejected();

  // Assert
  ASSERT_EQ(m_Output.str(), "Error: Order could not be added.\n");
}

TEST_F(GivenATextPresenter, WhenNoOrdersAreListedThenItSaysSo)
{
  // AAA: Arrange, Act, Assert
  // Act
  m_Presenter.ordersListed({});

  // Assert
  ASSERT_EQ(m_Output.str(), "No orders yet.\n");
}

TEST_F(GivenATextPresenter, WhenOrdersAreListedThenOnePerLineIsWritten)
{
  // AAA: Arrange, Act, Assert
  // Act
  m_Presenter.ordersListed({"CoffeeLatte, Sugar", "Cocoa"});

  // Assert
  ASSERT_EQ(m_Output.str(), "CoffeeLatte, Sugar\nCocoa\n");
}
} // namespace coffee_shop::interface_adapters
