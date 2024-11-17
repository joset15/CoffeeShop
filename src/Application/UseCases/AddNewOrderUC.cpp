#include "Application/UseCases/AddNewOrderUC.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

#include "Domain/BeverageBuilder/BeverageBuilder.hpp"
#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <iostream>
#include <memory>

bool AddNewOrderUC::execute()
{
  return addNewOrder(m_NewOrderReq.getBeverageType(),
                     m_NewOrderReq.getBeverageVariety(),
                     m_NewOrderReq.getIngredients());
};

bool AddNewOrderUC::addNewOrder(IBeverage::BeverageType beverageType,
                                BeverageVariety beverageVariety,
                                const std::list<Ingredient> &ingredients) const
{
  auto director = std::make_unique<BeverageBuildDirector>();

  std::shared_ptr<IBeverageBuilder> beverageBuilder =
      BeverageBuilderSimpleFactory::getInstance()->createBeverageBuilder(
          beverageVariety);

  director->setBuilder(beverageBuilder);

  if (!director->buildBeverage(beverageVariety, ingredients))
  {
    return false;
  }

  std::shared_ptr<IBeverage> newBeverage = beverageBuilder->getBeverage();
  std::cout << newBeverage->getDescription() << std::endl;

  // TODO add to the OrderRepository

  return true;
};
