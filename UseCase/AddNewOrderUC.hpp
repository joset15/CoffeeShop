#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

/*
#include "..\Model\Cocoa.hpp"
#include "..\Model\Coffee.hpp"
#include "..\Model\Tea.hpp"
*/

#include "../Model/Beverages/BeverageVariety.hpp"
#include "../Model/Beverages/IBeverage.hpp"

#include "../Model/Ingredient/IngredientDecorator.hpp"

#include "IOrderOutput.hpp"
#include "IOrderRepository.hpp"

class AddNewOrderUC
{
public:
  AddNewOrderUC(IOrderOutput &output, IOrderRepository &orderRepository)
      : m_Output(output), m_OrderRepository(orderRepository){};

  bool addNewOrder(IBeverage::BeverageType beverageType,
                   BeverageVariety beverageVariety,
                   IngredientDecorator *extraIngredient);

  bool cancelExistingOrders();

  bool printOutOrders();

  bool storeOrders();

private:
  IOrderOutput &m_Output;

  IOrderRepository &m_OrderRepository;
};

#endif // ADD_NEW_ORDER_UC_HPP
