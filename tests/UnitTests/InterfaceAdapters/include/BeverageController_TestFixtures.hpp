#ifndef BEVERAGE_CONTROLLER_TESTFIXTURES_HPP
#define BEVERAGE_CONTROLLER_TESTFIXTURES_HPP

#include "../../UseCases/include/OrderRepository_TestDoubles.hpp"

#include "Application/UseCases/NewOrderReq.hpp"
#include "InterfaceAdapters/BeverageController.hpp"

#include <gtest/gtest.h>

namespace CoffeeShop
{
///
/// \brief A fixture for a controller backed by an in-memory repository.
///
class GivenABeverageController : public ::testing::Test
{
protected:
  FakeOrderRepository m_OrderRepository;
  BeverageController m_BeverageController{m_OrderRepository};

  NewOrderReq m_ValidRequest{IBeverage::BeverageType::Coffee,
                             BeverageVariety::CoffeeEspresso,
                             {Ingredient::Sugar}};
  NewOrderReq m_InvalidRequest{IBeverage::BeverageType::Coffee,
                               BeverageVariety::CoffeeEspresso,
                               {Ingredient::Lemon}};
};
} // namespace CoffeeShop

#endif // BEVERAGE_CONTROLLER_TESTFIXTURES_HPP
