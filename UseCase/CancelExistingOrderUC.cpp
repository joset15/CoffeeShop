#include "AddNewOrderUC.hpp"

//#include "../Model/BeverageBuilder.hpp"
#include "../Model/BeverageBuilder/BeverageBuilder.hpp"

#include "../Model/BeverageFactories/BeverageFactory.hpp"
#include "../Model/BeverageFactories/IngredientFactory.hpp"

#include <iostream>
//#include <list>
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

bool AddNewOrderUC::addNewOrder(IBeverage::BeverageType beverageType,
                                BeverageVariety beverageVariety,
                                const std::list<Ingredient> &ingredients)
{
  /*
  std::shared_ptr<IBeverage> newBeverage =
    BeverageBuilder::getInstance()->getBeverage(beverageType, beverageVariety,
      extraIngredient);

  m_OrderRepository.save(std::move(newBeverage));
  */

  std::unique_ptr<BeverageBuildDirector> director =
      std::make_unique<BeverageBuildDirector>();

  // std::list<Ingredient> ingredients;
  // ingredients.push_back(Ingredient::Sugar);

  std::shared_ptr<CoffeeEspressoBuilder> coffeeEspressoBuilder =
      std::make_shared<CoffeeEspressoBuilder>(BeverageFactory::getInstance(),
                                              IngredientFactory::getInstance());
  director->setBuilder(coffeeEspressoBuilder);

  director->buildCoffeeEspresso(ingredients);

  std::shared_ptr<IBeverage> newBeverage4 =
      coffeeEspressoBuilder->getBeverage();
  std::cout << newBeverage4->getDescription() << std::endl;

  return true;
};

// TODO Develop Use Cases
bool AddNewOrderUC::cancelExistingOrders() { return true; }

bool AddNewOrderUC::printOutOrders() { return true; }

bool AddNewOrderUC::storeOrders() { return true; }
