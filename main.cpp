#include "UseCase/AddNewOrderUC.hpp"
#include "UseCase/NewOrderReq.hpp"

#include "Model/Beverages/BeverageVariety.hpp"
#include "Model/Beverages/Coffee.hpp"
#include "Model/Beverages/IBeverage.hpp"

#include "Model/Ingredient/Ingredients.hpp"

#include "Adapter/OrderRepository.hpp"
#include "Adapter/PrinterPresenter.hpp"

#include "Model/BeverageFactories/BeverageFactory.hpp"
#include "Model/BeverageFactories/IngredientFactory.hpp"

#include "Model/BeverageBuilder/BeverageBuilder.hpp"

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  std::shared_ptr<IBeverage> beverage = std::make_shared<Coffee>();
  beverage = std::make_shared<Sugar>(beverage);
  beverage = std::make_shared<Cream>(beverage);

  std::cout << beverage->getDescription() << std::endl;

  std::shared_ptr<IBeverage> newBeverage =
      BeverageFactory::getInstance()->createBeverage(
          BeverageVariety::CoffeeEspresso);

  std::cout << newBeverage->getDescription() << std::endl;

  // =============================================================
  std::unique_ptr<BeverageBuildDirector> director =
      std::make_unique<BeverageBuildDirector>();

  std::list<Ingredient> ingredients;
  ingredients.push_back(Ingredient::Sugar);

  std::shared_ptr<CoffeeEspressoBuilder> coffeeEspressoBuilder =
      std::make_shared<CoffeeEspressoBuilder>(BeverageFactory::getInstance(),
                                              IngredientFactory::getInstance());
  director->setBuilder(coffeeEspressoBuilder);

  director->buildCoffeeEspresso(ingredients);

  std::shared_ptr<IBeverage> newBeverage4 =
      coffeeEspressoBuilder->getBeverage();
  std::cout << newBeverage4->getDescription() << std::endl;

  //------------------
  std::shared_ptr<TeaBlackBuilder> teaBlackBuilder =
      std::make_shared<TeaBlackBuilder>(BeverageFactory::getInstance(),
                                        IngredientFactory::getInstance());
  director->setBuilder(teaBlackBuilder);

  director->buildTeaBlack(ingredients);

  std::shared_ptr<IBeverage> newBeverage5 = teaBlackBuilder->getBeverage();
  std::cout << newBeverage5->getDescription() << std::endl;

  //------------------
  /*
  PrinterPresenter printerPresenter; // IOutput & output
  OrderRepository orderRepository;
  AddNewOrderUC addNewOrderUC(std::string("AddNewOrderUC"), printerPresenter,
  orderRepository);

  IBeverage::BeverageType beverageType(IBeverage::BeverageType::Coffee);
  BeverageVariety beverageVariety(BeverageVariety::CoffeeEspresso);

  bool res =
      addNewOrderUC.addNewOrder(beverageType, beverageVariety, ingredients);
      */
  //------------------
  PrinterPresenter printerPresenter; // IOutput & output
  OrderRepository orderRepository;
  IBeverage::BeverageType beverageType(IBeverage::BeverageType::Coffee);
  BeverageVariety beverageVariety(BeverageVariety::CoffeeEspresso);
  NewOrderReq newOrderReq(beverageType, beverageVariety, ingredients,
                          printerPresenter, orderRepository);

  AddNewOrderUC addNewOrderUC(std::string("AddNewOrderUC"), newOrderReq);
  bool res = addNewOrderUC.execute();

  if (res)
  {
    std::cout << "Info: Coffee Espresso with Sugar ordered" << std::endl;
  }
  else
  {
    std::cout << "Error: Couldn't order an Espresso with sugar" << std::endl;
  }

  auto orderList = orderRepository.getOrders();
  printerPresenter.printOutOrders(orderList);

  return 0;
}
