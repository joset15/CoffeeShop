#include "AddNewOrderUC.hpp"
#include "../Model/BeverageBuilder.hpp"

#include <memory>

bool AddNewOrderUC::addNewOrder(IBeverage::BeverageType beverageType,
                                BeverageVariety beverageVariety,
                                IngredientDecorator *extraIngredient)
{
  /*
  std::shared_ptr<IBeverage> newBeverage =
    BeverageBuilder::getInstance()->getBeverage(beverageType, beverageVariety,
      extraIngredient);

  m_OrderRepository.save(std::move(newBeverage));
  */

  return true;
};

// TODO Develop Use Cases
bool AddNewOrderUC::cancelExistingOrders() { return true; }

bool AddNewOrderUC::printOutOrders() { return true; }

bool AddNewOrderUC::storeOrders() { return true; }
