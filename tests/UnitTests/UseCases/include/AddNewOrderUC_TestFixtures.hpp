#ifndef ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
#define ADD_NEW_ORDER_UC_TESTFIXTURES_HPP

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

#include "BeverageBuilderFactory_TestDoubles.hpp"
#include "DomainFactories_TestHelpers.hpp"
#include "OrderRepository_TestDoubles.hpp"
#include "OutputPort_TestDoubles.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::application
{
///
/// \brief A fixture for ordering an espresso with sugar (a valid mix).
///
class GivenAnEspressoWithSugarOrder : public ::testing::Test
{
protected:
  test_support::DomainFactories m_Factories;
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
  test_support::DomainFactories m_Factories;
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
  test_support::DomainFactories m_Factories;
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
  test_support::DomainFactories m_Factories;
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::Cocoa,
                        {domain::Ingredient::Milk}};
};

///
/// \brief A fixture for an order whose variety has no builder (the factory
/// returns nullptr, as it does for an invalid BeverageVariety value).
///
class GivenAnOrderForAVarietyWithNoBuilder : public ::testing::Test
{
protected:
  FakeBuilderFactoryWithNoVarieties m_BuilderFactory;
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::CoffeeEspresso,
                        {domain::Ingredient::Sugar}};
};

///
/// \brief A fixture for a valid order and a repository that can't save it.
///
class GivenARepositoryThatRejectsOrders : public ::testing::Test
{
protected:
  void SetUp() override { m_OrderRepository.rejectOrders(); }

  test_support::DomainFactories m_Factories;
  test_support::FakeOrderRepository m_OrderRepository;
  test_support::FakeAddNewOrderOutputPort m_OutputPort;
  NewOrderReq m_Request{domain::BeverageVariety::CoffeeEspresso,
                        {domain::Ingredient::Sugar}};
};
} // namespace coffee_shop::application

#endif // ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
