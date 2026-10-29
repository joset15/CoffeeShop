#ifndef CONSOLE_MENU_HPP
#define CONSOLE_MENU_HPP

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include <cstdint>
#include <istream>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

namespace coffee_shop::infrastructure::ui
{
/// @brief Text menus for the console app. Reads the user's choices from a
/// stream (std::cin in the app, a string in the tests).
class ConsoleMenu
{
public:
  /// @brief The options of the main menu.
  enum class MainOption : std::uint8_t
  {
    Quit = 0,
    AddOrder = 1,
    ScreenListOrders = 2,
    PrintListOrders = 3,
    CancelOrders = 4,
  };

  /// @brief Creates a menu that reads from and writes to the given streams.
  /// @param input Where the user's answers are read from.
  /// @param output Where the menus and messages are written to.
  ConsoleMenu(std::istream &input, std::ostream &output);

  /// @brief Shows the main menu and asks for an option.
  /// @return The option, or nullopt at the end of the input.
  [[nodiscard]] std::optional<MainOption> askMainOption();

  /// @brief Asks which beverage to order.
  /// @return The variety, or nullopt if cancelled (0) or at the end of the
  /// input.
  [[nodiscard]] std::optional<domain::BeverageVariety> askBeverageVariety();

  /// @brief Asks for the ingredients, as numbers on one line.
  /// @return The ingredients (empty for none or at the end of the input).
  [[nodiscard]] std::vector<domain::Ingredient> askIngredients();

  /// @brief Waits until the user presses Enter.
  void waitForEnter();

private:
  /// @brief Reads a number between minimum and maximum, asking again while
  /// the answer is not valid.
  /// @return The number, or nullopt at the end of the input.
  std::optional<int> askNumber(int minimum, int maximum);

  /// @brief Reads one line.
  /// @return False at the end of the input.
  bool readLine(std::string &line);

  /// @brief Where the user's answers are read from (not owned, never null).
  std::istream *m_Input;

  /// @brief Where the menus are written to (not owned, never null).
  std::ostream *m_Output;
};
} // namespace coffee_shop::infrastructure::ui

#endif // CONSOLE_MENU_HPP
