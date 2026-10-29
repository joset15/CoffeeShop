#ifndef BEVERAGE_DESCRIPTION_TESTHELPERS_HPP
#define BEVERAGE_DESCRIPTION_TESTHELPERS_HPP

#include <initializer_list>
#include <string>
#include <string_view>

namespace coffee_shop::test_support
{
/// @brief Builds the expected description of a beverage.
/// @param names The beverage name followed by its ingredient names.
/// @return For example describe({CoffeeName, SugarName}) == "Coffee, Sugar".
inline std::string describe(std::initializer_list<std::string_view> names)
{
  std::string description;
  for (const auto name : names)
  {
    if (!description.empty())
    {
      description.append(", ");
    }
    description.append(name);
  }
  return description;
}
} // namespace coffee_shop::test_support

#endif // BEVERAGE_DESCRIPTION_TESTHELPERS_HPP
