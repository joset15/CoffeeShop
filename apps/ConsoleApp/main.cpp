#include "Application/UseCases/AddNewOrderResponseMessage.hpp"
#include "Application/UseCases/NewOrderReq.hpp"
#include "Infrastructure/UI/ConsoleMenu.hpp"
#include "InterfaceAdapters/BeverageController.hpp"
#include "InterfaceAdapters/OrderRepository.hpp"
#include "InterfaceAdapters/PrinterPresenter.hpp"
#include "InterfaceAdapters/ScreenPresenter.hpp"

#include <crtdbg.h>
#include <iostream>

namespace
{
/// @brief Asks for a beverage and its ingredients, and orders it.
void addOrder(ConsoleMenu &menu, IOrderRepository &orderRepository)
{
  const auto beverageVariety = menu.askBeverageVariety();
  if (!beverageVariety)
  {
    return; // Cancelled.
  }
  const NewOrderReq newOrderReq(*beverageVariety, menu.askIngredients());

  const BeverageController beverageController(orderRepository);
  const AddNewOrderResponseMessage response =
      beverageController.execAddOrderUC(newOrderReq);

  ScreenPresenter screenPresenter;
  screenPresenter.print(response.getMessage());
}

/// @brief Shows the orders on the screen or sends them to the printer.
void listOrders(const OrderRepository &orderRepository, bool toPrinter)
{
  const auto &orders = orderRepository.getOrders();
  ScreenPresenter screenPresenter;
  if (orders.empty())
  {
    screenPresenter.print("No orders yet.");
  }
  else if (toPrinter)
  {
    PrinterPresenter printerPresenter;
    printerPresenter.printOutOrders(orders);
  }
  else
  {
    screenPresenter.print(orders);
  }
}
} // namespace

int main()
{
  // Report memory leaks when the program ends (MSVC debug CRT).
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  ConsoleMenu menu(std::cin, std::cout);
  OrderRepository orderRepository;

  while (true)
  {
    const auto option = menu.askMainOption();
    if (!option || *option == ConsoleMenu::MainOption::Quit)
    {
      return 0; // Exit chosen, or end of input.
    }

    switch (*option)
    {
    case ConsoleMenu::MainOption::AddOrder:
      addOrder(menu, orderRepository);
      break;
    case ConsoleMenu::MainOption::ScreenListOrders:
      listOrders(orderRepository, false);
      break;
    case ConsoleMenu::MainOption::PrintListOrders:
      listOrders(orderRepository, true);
      break;
    case ConsoleMenu::MainOption::Quit:
      break;
    }

    menu.waitForEnter();
  }
}
