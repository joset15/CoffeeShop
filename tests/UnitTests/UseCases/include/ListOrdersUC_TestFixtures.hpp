#ifndef LIST_ORDERS_UC_TESTFIXTURES_HPP
#define LIST_ORDERS_UC_TESTFIXTURES_HPP

#include "OrderRepository_TestDoubles.hpp"
#include "OutputPort_TestDoubles.hpp"

#include "Application/UseCases/ListOrdersUC.hpp"

#include <gtest/gtest.h>

namespace coffee_shop
{
///
/// \brief A fixture for listing the orders of an in-memory repository.
///
class GivenAnOrderRepository : public ::testing::Test
{
protected:
  FakeOrderRepository m_OrderRepository;
  FakeListOrdersOutputPort m_OutputPort;
};
} // namespace coffee_shop

#endif // LIST_ORDERS_UC_TESTFIXTURES_HPP
