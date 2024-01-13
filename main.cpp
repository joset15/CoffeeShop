#include "UseCase/UseCase.hpp"

#include "Model/BeverageVariety.hpp"
#include "Model/IBeverage.hpp"
#include "Model/Coffee.hpp"

#include "Model/Ingredient/Ingredients.hpp"

#include "Adapter/OrderRepository.hpp"
#include "Adapter/PrinterPresenter.hpp"

#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  {
    PrinterPresenter printerPresenter; // IOutput & output
    OrderRepository orderRepository;
    UseCase uc(printerPresenter, orderRepository);

    IBeverage::BeverageType beverageType(IBeverage::BeverageType::Coffee);
    BeverageVariety beverageVariety(BeverageVariety::CoffeeEspresso);
    //IngredientDecorator extraIngredient(IngredientDecorator::Sugar);

    std::shared_ptr<IBeverage> beverage = std::make_shared<Coffee>();
    beverage = std::make_shared<Sugar>(beverage);
    beverage = std::make_shared<Cream>(beverage);

    std::cout << beverage->getDescription();

    // bool res = uc.addNewOrder(beverageType, beverageVariety, extraIngredient);
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
