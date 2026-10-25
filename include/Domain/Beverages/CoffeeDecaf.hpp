#ifndef COFFEE_DECAF_HPP
#define COFFEE_DECAF_HPP

#include "../Beverages/IBeverage.hpp"
#include <string>
#include <string_view>

/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CoffeeDecafName = "CoffeeDecaf";

class CoffeeDecaf : public IBeverage
{
public:
  CoffeeDecaf() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CoffeeDecafName);
  }
};

#endif // COFFEE_DECAF_HPP
