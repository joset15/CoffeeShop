#ifndef CANCEL_ORDERS_UC_TESTFIXTURES_HPP
#define CANCEL_ORDERS_UC_TESTFIXTURES_HPP

#include "Application/UseCases/CancelOrdersUC.hpp"

#include "OrderRepository_TestDoubles.hpp"
#include "OutputPort_TestDoubles.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::application
{
///
/// \brief A fixture for cancelling the orders of an in-memory repository.
///
class GivenACancelOrdersUseCase : public ::testing::Test
{
protected:
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeCancelOrdersOutputPort m_OutputPort;
  CancelOrdersUC m_CancelOrdersUC{m_OrderRepository, m_OutputPort};
};
} // namespace coffee_shop::application

#endif // CANCEL_ORDERS_UC_TESTFIXTURES_HPP
