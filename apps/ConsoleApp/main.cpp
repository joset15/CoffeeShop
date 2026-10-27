#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

#include "InterfaceAdapters/BeverageController.hpp"
#include "InterfaceAdapters/OrderRepository.hpp"
#include "InterfaceAdapters/TextPresenter.hpp"

#include "Infrastructure/UI/ConsoleMenu.hpp"

#include <crtdbg.h>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>

using coffee_shop::application::NewOrderReq;
using coffee_shop::domain::BeverageBuilderSimpleFactory;
using coffee_shop::domain::BeverageFactory;
using coffee_shop::domain::IngredientFactory;
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
  // Composition root: create every dependency and wire them together.
  BeverageFactory beverageFactory;
  IngredientFactory ingredientFactory;
  BeverageBuilderSimpleFactory beverageBuilderFactory(beverageFactory,
                                                      ingredientFactory);
  OrderRepository orderRepository;
  const BeverageController controller(beverageBuilderFactory, orderRepository);
  ConsoleMenu menu(std::cin, std::cout);
  TextPresenter screenPresenter(std::cout);

  while (true)
  {
    using enum ConsoleMenu::MainOption;

    const auto option = menu.askMainOption();
    if (!option || *option == Quit)
    {
      return; // Exit chosen, or end of input.
    }

    switch (*option)
    {
    case AddOrder:
      addOrder(menu, controller, screenPresenter);
      break;
    case ScreenListOrders:
      controller.listOrders(screenPresenter);
      break;
    case PrintListOrders:
      printOrders(controller);
      break;
    case CancelOrders:
      controller.cancelOrders(screenPresenter);
      break;
    case Quit:
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
