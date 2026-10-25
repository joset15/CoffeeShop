#ifndef COFFEE_LATTE_HPP
#define COFFEE_LATTE_HPP

#include "IBeverage.hpp"
#include <string>
#include <string_view>

/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CoffeeLatteName = "CoffeeLatte";

class CoffeeLatte : public IBeverage
{
public:
  CoffeeLatte() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CoffeeLatteName);
  }
};

#endif // COFFEE_LATTE_HPP
