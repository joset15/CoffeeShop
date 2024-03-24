#include "AddNewOrderUC.hpp"

#include "../Model/BeverageBuilder/BeverageBuilder.hpp"
#include "../Model/BeverageFactories/BeverageBuilderFactory.hpp"
#include "../Model/BeverageFactories/BeverageFactory.hpp"
#include "../Model/BeverageFactories/IngredientFactory.hpp"

#include <iostream>
#include <memory>

bool AddNewOrderUC::addNewOrder(IBeverage::BeverageType beverageType,
                                BeverageVariety beverageVariety,
                                const std::list<Ingredient> &ingredients)
{
  std::unique_ptr<BeverageBuildDirector> director =
      std::make_unique<BeverageBuildDirector>();

  std::shared_ptr<IBeverageBuilder> beverageBuilder =
      BeverageBuilderFactory::getInstance()->createBeverageBuilder(
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
