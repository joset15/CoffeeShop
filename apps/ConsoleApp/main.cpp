#include "Application/UseCases/NewOrderReq.hpp"
#include "Infrastructure/UI/ConsoleMenu.hpp"
#include "InterfaceAdapters/BeverageController.hpp"
#include "InterfaceAdapters/OrderRepository.hpp"
#include "InterfaceAdapters/TextPresenter.hpp"

#include <crtdbg.h>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>

using coffee_shop::application::NewOrderReq;
using coffee_shop::infrastructure::ui::ConsoleMenu;
using coffee_shop::interface_adapters::BeverageController;
using coffee_shop::interface_adapters::OrderRepository;
using coffee_shop::interface_adapters::TextPresenter;

namespace
{
/// @brief The file where "Print list beverage orders" writes the orders.
constexpr const char *PrintFileName = "orders.txt";

/// @brief Asks for a beverage and its ingredients, and orders it.
void addOrder(ConsoleMenu &menu, const BeverageController &controller,
              TextPresenter &presenter)
{
  const auto beverageVariety = menu.askBeverageVariety();
  if (!beverageVariety)
  {
    return; // Cancelled.
  }
  controller.addOrder(NewOrderReq(*beverageVariety, menu.askIngredients()),
                      presenter);
}

/// @brief "Prints" the orders: writes them to PrintFileName in the current
/// folder, replacing its previous content.
void printOrders(const BeverageController &controller)
{
  const std::filesystem::path path = std::filesystem::absolute(PrintFileName);
  std::ofstream file(path);
  if (file)
  {
    TextPresenter filePresenter(file);
    controller.listOrders(filePresenter);
    file.close();
  }

  if (!file)
  {
    std::cout << "Error: Could not write " << path.string() << ".\n";
    return;
  }
  std::cout << "Info: Orders printed to " << path.string() << ".\n";
}

/// @brief Runs the main menu until the user quits or the input ends.
void run()
{
  ConsoleMenu menu(std::cin, std::cout);
  OrderRepository orderRepository;
  const BeverageController controller(orderRepository);
  TextPresenter screenPresenter(std::cout);

  while (true)
  {
    const auto option = menu.askMainOption();
    if (!option || *option == ConsoleMenu::MainOption::Quit)
    {
      return; // Exit chosen, or end of input.
    }

    switch (*option)
    {
    case ConsoleMenu::MainOption::AddOrder:
      addOrder(menu, controller, screenPresenter);
      break;
    case ConsoleMenu::MainOption::ScreenListOrders:
      controller.listOrders(screenPresenter);
      break;
    case ConsoleMenu::MainOption::PrintListOrders:
      printOrders(controller);
      break;
    case ConsoleMenu::MainOption::Quit:
      break;
    }

    menu.waitForEnter();
  }
}
} // namespace

int main()
{
  // Report memory leaks when the program ends (MSVC debug CRT).
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  try
  {
    run();
    return EXIT_SUCCESS;
  }
  // std::fputs can't throw, unlike std::cerr, so nothing escapes main().
  catch (const std::exception &error)
  {
    std::fputs("Fatal error: ", stderr);
    std::fputs(error.what(), stderr);
    std::fputs("\n", stderr);
  }
  catch (...)
  {
    std::fputs("Fatal error: unknown exception.\n", stderr);
  }
  return EXIT_FAILURE;
}
