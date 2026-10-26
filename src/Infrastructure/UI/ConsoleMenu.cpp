#include "Infrastructure/UI/ConsoleMenu.hpp"

#include <array>
#include <charconv>
#include <sstream>
#include <string_view>

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

/// @brief The beverages, in menu order (entry N is option N + 1).
constexpr std::array<MenuEntry<domain::BeverageVariety>, 6> BeverageEntries{{
    {domain::BeverageVariety::CoffeeEspresso, "Coffee espresso"},
    {domain::BeverageVariety::CoffeeLatte, "Coffee latte"},
    {domain::BeverageVariety::CoffeeDecaf, "Coffee decaf"},
    {domain::BeverageVariety::TeaBlack, "Black tea"},
    {domain::BeverageVariety::TeaGreen, "Green tea"},
    {domain::BeverageVariety::Cocoa, "Cocoa"},
}};

/// @brief The ingredients, in menu order (entry N is option N + 1).
constexpr std::array<MenuEntry<domain::Ingredient>, 7> IngredientEntries{{
    {domain::Ingredient::Sugar, "Sugar"},
    {domain::Ingredient::Milk, "Milk"},
    {domain::Ingredient::Cream, "Cream"},
    {domain::Ingredient::Honey, "Honey"},
    {domain::Ingredient::Lemon, "Lemon"},
    {domain::Ingredient::SoyMilk, "Soy milk"},
    {domain::Ingredient::Water, "Water"},
}};

/// @brief Parses a whole word as a number.
/// @return The number, or nullopt if the word is not a number.
std::optional<int> parseNumber(std::string_view word)
{
  int number = 0;
  if (const auto result =
          std::from_chars(word.data(), word.data() + word.size(), number);
      result.ec != std::errc{} || result.ptr != word.data() + word.size())
  {
    return std::nullopt;
  }
  return number;
}

/// @brief Writes the entries as a numbered list, starting at 1.
template <typename Entries>
void printEntries(std::ostream &output, const Entries &entries)
{
  int number = 1;
  for (const auto &entry : entries)
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
            << "  0. Exit\n";

  const auto number = askNumber(static_cast<int>(MainOption::Quit),
                                static_cast<int>(MainOption::PrintListOrders));
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
