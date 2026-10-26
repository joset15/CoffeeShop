#ifndef COFFEE_LATTE_HPP
#define COFFEE_LATTE_HPP

#include "Coffee.hpp"
#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CoffeeLatteName = "CoffeeLatte";

class CoffeeLatte : public Coffee
{
public:
  CoffeeLatte() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CoffeeLatteName);
  }
};
} // namespace coffee_shop::domain

#endif // COFFEE_LATTE_HPP
