#ifndef COFFEE_DECAF_HPP
#define COFFEE_DECAF_HPP

#include "Coffee.hpp"
#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CoffeeDecafName = "CoffeeDecaf";

class CoffeeDecaf : public Coffee
{
public:
  CoffeeDecaf() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CoffeeDecafName);
  }
};
} // namespace coffee_shop::domain

#endif // COFFEE_DECAF_HPP
