#ifndef LIST_ORDERS_UC_TESTFIXTURES_HPP
#define LIST_ORDERS_UC_TESTFIXTURES_HPP

#include "OrderRepository_TestDoubles.hpp"
#include "OutputPort_TestDoubles.hpp"

#include "Application/UseCases/ListOrdersUC.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::application
{
///
/// \brief A fixture for listing the orders of an in-memory repository.
///
class GivenAnOrderRepository : public ::testing::Test
{
protected:
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeListOrdersOutputPort m_OutputPort;
};
} // namespace coffee_shop::application

#endif // LIST_ORDERS_UC_TESTFIXTURES_HPP
