#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/Coffee.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include "Domain/Ingredients/Ingredients.hpp"

#include "Adapter/OrderRepository.hpp"
#include "Adapter/PrinterPresenter.hpp"
#include "Adapter/ScreenPresenter.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include "Domain/BeverageBuilder/BeverageBuilder.hpp"

#include "UseCase/AddNewOrderUC.hpp"
#include "UseCase/NewOrderReq.hpp"

#include "Adapter/BeverageController.hpp"

//#include <conio.h> //clrscr(), getch()
#include <iostream>
#include <memory>
#include <stdlib.h> // system("cls"); system("pause")

int consoleMenu();

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
  auto director = std::make_unique<BeverageBuildDirector>();

  std::list<Ingredient> ingredients;
  ingredients.push_back(Ingredient::Sugar);

  auto coffeeEspressoBuilder = std::make_shared<CoffeeEspressoBuilder>(
      BeverageFactory::getInstance(), IngredientFactory::getInstance());
  director->setBuilder(coffeeEspressoBuilder);

  director->buildCoffeeEspresso(ingredients);

  std::shared_ptr<IBeverage> newBeverage4 =
      coffeeEspressoBuilder->getBeverage();
  std::cout << newBeverage4->getDescription() << std::endl;

  //------------------
  auto teaBlackBuilder = std::make_shared<TeaBlackBuilder>(
      BeverageFactory::getInstance(), IngredientFactory::getInstance());
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
  NewOrderReq newOrderReq(beverageType, beverageVariety, ingredients);
  //                          printerPresenter, orderRepository);

  AddNewOrderUC addNewOrderUC(std::string("AddNewOrderUC"), newOrderReq,
                              orderRepository);
  bool res = addNewOrderUC.execute();

  if (res)
  {
    std::cout << "Info: Coffee Espresso with Sugar ordered" << std::endl;
  }
  else
  {
    std::cout << "Error: Couldn't order an Espresso with sugar" << std::endl;
  }

  const auto &orderList = orderRepository.getOrders();
  printerPresenter.printOutOrders(orderList);

  //------------------

  /*int resMenu =*/consoleMenu();

  return 0;
}

int consoleMenu()
{
  constexpr int AddOrderCommand = 1;
  constexpr int ScreenListOrdersCommand = 2;
  constexpr int PrintListOrdersCommand = 3;
  constexpr int QuitCommand = 0;

  OrderRepository orderRepository;
  int userInput = 0;

  do
  {
    system("cls");

    // Show Main menu options (Add order, list order...)
    std::cout << "Main menu" << std::endl;
    std::cout << "1. Add beverage order" << std::endl;
    std::cout << "2. Screen list beverage orders" << std::endl;
    std::cout << "3. Print list beverage orders" << std::endl;
    std::cout << "0. Exit" << std::endl;

    std::cin >> userInput;

    if (userInput == AddOrderCommand)
    {
      //*************************************************************************************************
      // Here we're connecting our app framework layer with our Use Case
      // Interactors This would typically go in a Controller Action in an MVC
      // context or ViewModel in MVVM etc.
      //*************************************************************************************************
      // 1. instantiate "Add Beverage Order" Use Case injecting Gateways
      // implemented in this layer

      NewOrderReq newOrderReq(IBeverage::BeverageType::Coffee,
                              BeverageVariety::CoffeeEspresso,
                              {Ingredient::Sugar});
      AddNewOrderResponseMessage response;

      BeverageController beverageController(orderRepository);
      response = beverageController.execAddOrderUC(newOrderReq);

      ScreenPresenter screenPresenter;
      screenPresenter.print(response.getMessage()); // getErrors()
      screenPresenter.print("");

      if (!response.getSuccess())
      {
        // screenPresenter.print(response.getErrors());
      }
    }
    else if (userInput == ScreenListOrdersCommand)
    {
      ScreenPresenter screenPresenter;
      const auto &orderList = orderRepository.getOrders();
      screenPresenter.print(orderList);
    }
    else if (userInput == PrintListOrdersCommand)
    {
      PrinterPresenter printerPresenter;
      const auto &orderList = orderRepository.getOrders();
      printerPresenter.printOutOrders(orderList);
    }

    if (userInput != QuitCommand)
    {
      system("pause");
    }

  } while (userInput != QuitCommand);

  return 0;
}