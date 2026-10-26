#ifndef WATER_HPP
#define WATER_HPP

#include "IngredientDecorator.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view WaterName = "Water";

class Water : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(WaterName);
  }
};
} // namespace coffee_shop::domain

#endif // WATER_HPP
