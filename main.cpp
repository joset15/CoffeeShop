#include "UseCase/UseCase.hpp"

#include "Model/BeverageVariety.hpp"
#include "Model/Coffee.hpp"
#include "Model/IBeverage.hpp"

#include "Model/Ingredient/Ingredients.hpp"

#include "Adapter/OrderRepository.hpp"
#include "Adapter/PrinterPresenter.hpp"

#include "Model/BeverageFactory.hpp"

#include "Model/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Model/BeverageBuilder/CoffeeBuilder.hpp"
#include "Model/BeverageBuilder/TeaBuilder.hpp"

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  // Don't delete: scope needed to memory leak report
  {
    PrinterPresenter printerPresenter; // IOutput & output
    OrderRepository orderRepository;
    UseCase uc(printerPresenter, orderRepository);

    IBeverage::BeverageType beverageType(IBeverage::BeverageType::Coffee);
    BeverageVariety beverageVariety(BeverageVariety::CoffeeEspresso);
    // IngredientDecorator extraIngredient(IngredientDecorator::Sugar);

    std::shared_ptr<IBeverage> beverage = std::make_shared<Coffee>();
    beverage = std::make_shared<Sugar>(beverage);
    beverage = std::make_shared<Cream>(beverage);

    std::cout << beverage->getDescription() << std::endl;

    std::shared_ptr<IBeverage> newBeverage =
        BeverageFactory::getInstance()->createBeverage(
            BeverageVariety::CoffeeEspresso);

    std::cout << newBeverage->getDescription() << std::endl;

    //------------------------------------------------------------------------------
    std::shared_ptr<IBeverage> newBeverage2 =
        BeverageFactory::getInstance()->createBeverage(
            BeverageVariety::CoffeeEspresso);

    std::shared_ptr<IngredientDecorator> newIngredient =
        std::make_shared<Sugar>(Ingredient::Sugar);

    // if (!newBeverage2->addIngredient(newIngredient.get()))
    if (!newIngredient->addToBeverage(newBeverage2))
    {
      std::cout << "newBeverage2 Error" << std::endl;
    }
    std::cout << newBeverage2->getDescription() << std::endl;
    std::cout << newIngredient->getDescription() << std::endl;

    // =============================================================

    std::unique_ptr<BeverageBuildDirector> director =
        std::make_unique<BeverageBuildDirector>();
    std::shared_ptr<CoffeeBuilder> coffeeBuilder =
        std::make_shared<CoffeeBuilder>();
    director->setBuilder(coffeeBuilder);

    std::list<Ingredient> ingredients;
    ingredients.push_back(Ingredient::Sugar);
    director->buildCoffee(ingredients);

    std::shared_ptr<IBeverage> newBeverage3 = coffeeBuilder->getBeverage();
    std::cout << newBeverage3->getDescription() << std::endl;

    // bool res = uc.addNewOrder(beverageType, beverageVariety,
    // extraIngredient);
    /*
    if (res)
    {
      std::cout << "Info: Coffee Espresso with Sugar ordered" << std::endl;
    }
    else
    {
      std::cout << "Error: Couldn't order an Expresso with sugar" << std::endl;
    }

    auto orderList = orderRepository.getOrders();
    printerPresenter.printOutOrders(orderList);
    */
  }

  _CrtDumpMemoryLeaks();

  return 0;
}
