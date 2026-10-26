#ifndef COFFEE_ESPRESSO_HPP
#define COFFEE_ESPRESSO_HPP

#include "Domain/Beverages/Coffee.hpp"
#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CoffeeEspressoName = "CoffeeEspresso";

class CoffeeEspresso : public Coffee
{
public:
  CoffeeEspresso() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CoffeeEspressoName);
  }
};
} // namespace coffee_shop::domain

#endif // COFFEE_ESPRESSO_HPP
