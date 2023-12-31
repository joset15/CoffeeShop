#include "UseCase.hpp"
#include "..\Model\BeverageBuilder.hpp"

#include <memory>

bool UseCase::addNewOrder(IBeverage::BeverageType beverageType,
                          BeverageVariety beverageVariety,
                          Ingredient extraIngredient)
{

  std::shared_ptr<IBeverage> newBeverage =
      BeverageBuilder::getInstance()->getBeverage(beverageType, beverageVariety,
                                                  extraIngredient);

  m_OrderRepository.save(std::move(newBeverage));

  return true;
};

// TODO Develop Use Cases
bool UseCase::cancelExistingOrders() { return true; }

bool UseCase::printOutOrders() { return true; }

bool UseCase::storeOrders() { return true; }
