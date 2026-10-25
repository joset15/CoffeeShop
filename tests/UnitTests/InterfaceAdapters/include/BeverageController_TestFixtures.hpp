#ifndef BEVERAGE_CONTROLLER_TESTFIXTURES_HPP
#define BEVERAGE_CONTROLLER_TESTFIXTURES_HPP

#include "../../UseCases/include/OrderRepository_TestDoubles.hpp"
#include "../../UseCases/include/OutputPort_TestDoubles.hpp"

#include "Application/UseCases/NewOrderReq.hpp"
#include "InterfaceAdapters/BeverageController.hpp"

#include <gtest/gtest.h>

namespace coffee_shop
{
///
/// \brief A fixture for a controller backed by an in-memory repository, with
/// output ports that record the results.
///
class GivenABeverageController : public ::testing::Test
{
protected:
  FakeOrderRepository m_OrderRepository;
  BeverageController m_BeverageController{m_OrderRepository};
  FakeAddNewOrderOutputPort m_AddNewOrderOutputPort;
  FakeListOrdersOutputPort m_ListOrdersOutputPort;

  NewOrderReq m_ValidRequest{BeverageVariety::CoffeeEspresso,
                             {Ingredient::Sugar}};
  NewOrderReq m_InvalidRequest{BeverageVariety::CoffeeEspresso,
                               {Ingredient::Lemon}};
};
} // namespace coffee_shop

#endif // BEVERAGE_CONTROLLER_TESTFIXTURES_HPP
