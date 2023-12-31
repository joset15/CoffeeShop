#include "UseCase/UseCase.hpp"

#include "Model/BeverageVariety.hpp"
#include "Model/IBeverage.hpp"
#include "Model/Ingredient.hpp"

#include "Adapter/OrderRepository.hpp"
#include "Adapter/PrinterPresenter.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
  PrinterPresenter printerPresenter; // IOutput & output
  OrderRepository orderRepository;
  UseCase uc(printerPresenter, orderRepository);

  IBeverage::BeverageType beverageType(IBeverage::BeverageType::Coffee);
  BeverageVariety beverageVariety(BeverageVariety::CoffeeEspresso);
  Ingredient extraIngredient(Ingredient::Sugar);

  bool res = uc.addNewOrder(beverageType, beverageVariety, extraIngredient);
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

  return 0;
}
