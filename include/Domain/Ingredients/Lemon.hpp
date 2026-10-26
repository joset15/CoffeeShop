#ifndef LEMON_HPP
#define LEMON_HPP

#include "IngredientDecorator.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view LemonName = "Lemon";

class Lemon : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(LemonName);
  }
};
} // namespace coffee_shop::domain

#endif // LEMON_HPP
