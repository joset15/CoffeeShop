#ifndef ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
#define ADD_NEW_ORDER_UC_TESTFIXTURES_HPP

#include "OrderRepository_TestDoubles.hpp"
#include "OutputPort_TestDoubles.hpp"

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::application
{
///
/// \brief A fixture for ordering an espresso with sugar (a valid mix).
///
class GivenAnEspressoWithSugarOrder : public ::testing::Test
{
protected:
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::CoffeeEspresso,
                        {domain::Ingredient::Sugar}};
};

///
/// \brief A fixture for ordering an espresso with lemon (an invalid mix).
///
class GivenAnEspressoWithLemonOrder : public ::testing::Test
{
protected:
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::CoffeeEspresso,
                        {domain::Ingredient::Lemon}};
};

///
/// \brief A fixture for ordering a latte with sugar.
///
class GivenALatteOrder : public ::testing::Test
{
protected:
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::CoffeeLatte,
                        {domain::Ingredient::Sugar}};
};
///
/// \brief A fixture for ordering a cocoa with milk.
///
class GivenACocoaWithMilkOrder : public ::testing::Test
{
protected:
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::Cocoa,
                        {domain::Ingredient::Milk}};
};
} // namespace coffee_shop::application

#endif // ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
