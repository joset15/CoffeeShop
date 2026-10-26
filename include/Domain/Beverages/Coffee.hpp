#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "IBeverage.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CoffeeName = "Coffee";

class Coffee : public IBeverage
{
public:
  Coffee() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CoffeeName);
  }
};
} // namespace coffee_shop::domain

#endif // COFFEE_HPP
