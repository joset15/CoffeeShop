#ifndef ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
#define ADD_NEW_ORDER_UC_TESTFIXTURES_HPP

#include "OrderRepository_TestDoubles.hpp"

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

#include <gtest/gtest.h>

namespace CoffeeShop
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
} // namespace CoffeeShop

#endif // ADD_NEW_ORDER_UC_TESTFIXTURES_HPP
