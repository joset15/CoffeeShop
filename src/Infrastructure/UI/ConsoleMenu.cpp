#include "Infrastructure/UI/ConsoleMenu.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include <array>
#include <charconv>
#include <cstddef>
#include <istream>
#include <memory>
#include <optional>
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

namespace coffee_shop::infrastructure::ui
{
namespace
{
/// @brief A menu entry: what the user sees and what it selects.
template <typename ValueType> struct MenuEntry
{
  ValueType m_Value;
  std::string_view m_Label;
};

// The enumerators of both enums, so each table row fits on one line (their
// names don't clash).
using enum domain::BeverageVariety;
using enum domain::Ingredient;

/// @brief The beverages, in menu order (entry N is option N + 1).
constexpr auto BeverageEntries =
    std::to_array<MenuEntry<domain::BeverageVariety>>({
        {.m_Value = CoffeeEspresso, .m_Label = "Coffee espresso"},
        {.m_Value = CoffeeLatte, .m_Label = "Coffee latte"},
        {.m_Value = CoffeeDecaf, .m_Label = "Coffee decaf"},
        {.m_Value = TeaBlack, .m_Label = "Black tea"},
        {.m_Value = TeaGreen, .m_Label = "Green tea"},
        {.m_Value = Cocoa, .m_Label = "Cocoa"},
    });

/// @brief The ingredients, in menu order (entry N is option N + 1).
constexpr auto IngredientEntries =
    std::to_array<MenuEntry<domain::Ingredient>>({
        {.m_Value = Sugar, .m_Label = "Sugar"},
        {.m_Value = Milk, .m_Label = "Milk"},
        {.m_Value = Cream, .m_Label = "Cream"},
        {.m_Value = Honey, .m_Label = "Honey"},
        {.m_Value = Lemon, .m_Label = "Lemon"},
        {.m_Value = SoyMilk, .m_Label = "Soy milk"},
        {.m_Value = Water, .m_Label = "Water"},
    });

/// @brief Parses a whole word as a number.
/// @return The number, or nullopt if the word is not a number.
std::optional<int> parseNumber(std::string_view word)
{
  int number = 0;
  const char *const first = std::to_address(word.begin());
  const char *const last = std::to_address(word.end());
  if (const auto result = std::from_chars(first, last, number);
      result.ec != std::errc{} || result.ptr != last)
  {
    return std::nullopt;
  }
  return number;
}

/// @brief Writes the entries as a numbered list, starting at 1.
template <typename Entries>
void printEntries(std::ostream &output, const Entries &entries)
{
  for (int number = 1; const auto &entry : entries)
  {
    output << "  " << number << ". " << entry.m_Label << '\n';
    ++number;
  }
}
} // namespace

ConsoleMenu::ConsoleMenu(std::istream &input, std::ostream &output)
    : m_Input(&input), m_Output(&output)
{
}

std::optional<ConsoleMenu::MainOption> ConsoleMenu::askMainOption()
{
  *m_Output << "Main menu\n"
            << "  1. Add beverage order\n"
            << "  2. Screen list beverage orders\n"
            << "  3. Print list beverage orders\n"
            << "  4. Cancel all orders\n"
            << "  0. Exit\n";

  const auto number = askNumber(static_cast<int>(MainOption::Quit),
                                static_cast<int>(MainOption::CancelOrders));
  if (!number)
  {
    return std::nullopt;
  }
  return static_cast<MainOption>(*number);
}

std::optional<domain::BeverageVariety> ConsoleMenu::askBeverageVariety()
{
  *m_Output << "Choose a beverage (0 to cancel):\n";
  printEntries(*m_Output, BeverageEntries);

  const auto number = askNumber(0, static_cast<int>(BeverageEntries.size()));
  if (!number || *number == 0)
  {
    return std::nullopt;
  }
  return BeverageEntries.at(static_cast<std::size_t>(*number - 1)).m_Value;
}

std::vector<domain::Ingredient> ConsoleMenu::askIngredients()
{
  *m_Output << "Choose ingredients (numbers separated by spaces, Enter for "
               "none):\n";
  printEntries(*m_Output, IngredientEntries);

  const int maximum = static_cast<int>(IngredientEntries.size());
  std::string line;
  while (readLine(line))
  {
    std::vector<domain::Ingredient> ingredients;
    bool valid = true;
    std::istringstream words(line);
    std::string word;
    while (words >> word)
    {
      const auto number = parseNumber(word);
      if (!number || *number < 1 || *number > maximum)
      {
        valid = false;
        break;
      }
      ingredients.push_back(
          IngredientEntries.at(static_cast<std::size_t>(*number - 1)).m_Value);
    }

    if (valid)
    {
      return ingredients;
    }
    *m_Output << "Please enter numbers between 1 and " << maximum
              << ", separated by spaces.\n";
  }
  return {};
}

void ConsoleMenu::waitForEnter()
{
  *m_Output << "Press Enter to continue...\n";
  std::string line;
  readLine(line);
}

std::optional<int> ConsoleMenu::askNumber(int minimum, int maximum)
{
  std::string line;
  while (readLine(line))
  {
    std::istringstream words(line);
    std::string word;
    std::string extra;
    if (words >> word && !(words >> extra))
    {
      if (const auto number = parseNumber(word);
          number && *number >= minimum && *number <= maximum)
      {
        return number;
      }
    }
    *m_Output << "Please enter a number between " << minimum << " and "
              << maximum << ".\n";
  }
  return std::nullopt;
}

bool ConsoleMenu::readLine(std::string &line)
{
  *m_Output << "> " << std::flush;
  return static_cast<bool>(std::getline(*m_Input, line));
}
} // namespace coffee_shop::infrastructure::ui
