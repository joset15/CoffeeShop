#ifndef ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
#define ADD_NEW_ORDER_UC_TESTFIXTURES_HPP

#include "OrderRepository_TestDoubles.hpp"

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

#include <gtest/gtest.h>

namespace coffee_shop
{
///
/// \brief A fixture for ordering an espresso with sugar (a valid mix).
///
class GivenAnEspressoWithSugarOrder : public ::testing::Test
{
protected:
  FakeOrderRepository m_OrderRepository;
  NewOrderReq m_Request{IBeverage::BeverageType::Coffee,
                        BeverageVariety::CoffeeEspresso,
                        {Ingredient::Sugar}};
};

///
/// \brief A fixture for ordering an espresso with lemon (an invalid mix).
///
class GivenAnEspressoWithLemonOrder : public ::testing::Test
{
protected:
  FakeOrderRepository m_OrderRepository;
  NewOrderReq m_Request{IBeverage::BeverageType::Coffee,
                        BeverageVariety::CoffeeEspresso,
                        {Ingredient::Lemon}};
};

///
/// \brief A fixture for ordering a latte, a variety without a builder yet.
///
class GivenALatteOrder : public ::testing::Test
{
protected:
  FakeOrderRepository m_OrderRepository;
  NewOrderReq m_Request{IBeverage::BeverageType::Coffee,
                        BeverageVariety::CoffeeLatte,
                        {Ingredient::Sugar}};
};
} // namespace coffee_shop

#endif // ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
