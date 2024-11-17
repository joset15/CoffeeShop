#ifndef BEVERAGE_CONTROLLER_HPP
#define BEVERAGE_CONTROLLER_HPP

#pragma once

//#include "UseCase/IUseCaseOutputPort.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

/*
#include "Model/Beverages/BeverageVariety.hpp"
#include "Model/Beverages/Coffee.hpp"
#include "Model/Beverages/IBeverage.hpp"

#include "Model/Ingredient/Ingredients.hpp"
*/

#include "OrderRepository.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include "Application/UseCases/AddNewOrderResponseMessage.hpp"
#include "Domain/BeverageBuilder/BeverageBuilder.hpp"

class BeverageController
{
public:
  BeverageController(const OrderRepository &orderRepository)
      : m_OrderRepository(orderRepository){};

  AddNewOrderResponseMessage
  execAddOrderUC(const NewOrderReq &newOrderReq) const;

  // void execListOrderUC(const ListOrderReq &listOrderReq) {}
  void execListOrderUC(const IRequest &listOrderReq) {}

private:
  const OrderRepository &m_OrderRepository;
};

#endif // BEVERAGE_CONTROLLER_HPP