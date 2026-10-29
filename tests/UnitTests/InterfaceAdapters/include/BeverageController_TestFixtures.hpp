#ifndef BEVERAGE_CONTROLLER_TESTFIXTURES_HPP
#define BEVERAGE_CONTROLLER_TESTFIXTURES_HPP

#include "Application/UseCases/NewOrderReq.hpp"

#include "InterfaceAdapters/BeverageController.hpp"

#include "DomainFactories_TestHelpers.hpp"
#include "OrderRepository_TestDoubles.hpp"
#include "OutputPort_TestDoubles.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::interface_adapters
{
///
/// \brief A fixture for a controller backed by an in-memory repository, with
/// output ports that record the results.
///
class GivenABeverageController : public ::testing::Test
{
protected:
  test_support::DomainFactories m_Factories;
  test_support::FakeOrderRepository m_OrderRepository;
  BeverageController m_BeverageController{m_Factories.m_BuilderFactory,
                                          m_OrderRepository};
  test_support::FakeAddNewOrderOutputPort m_AddNewOrderOutputPort;
  test_support::FakeListOrdersOutputPort m_ListOrdersOutputPort;
  test_support::FakeCancelOrdersOutputPort m_CancelOrdersOutputPort;

  application::NewOrderReq m_ValidRequest{
      domain::BeverageVariety::CoffeeEspresso, {domain::Ingredient::Sugar}};
  application::NewOrderReq m_InvalidRequest{
      domain::BeverageVariety::CoffeeEspresso, {domain::Ingredient::Lemon}};
};
} // namespace coffee_shop::interface_adapters

#endif // BEVERAGE_CONTROLLER_TESTFIXTURES_HPP
