#ifndef MILK_HPP
#define MILK_HPP

#include "Domain/Ingredients/IngredientDecorator.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view MilkName = "Milk";

class Milk : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(MilkName);
  }
};
} // namespace coffee_shop::domain

#endif // MILK_HPP
