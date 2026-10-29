#ifndef SOYMILK_HPP
#define SOYMILK_HPP

#include "Domain/Ingredients/IngredientDecorator.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view SoyMilkName = "SoyMilk";

class SoyMilk : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(SoyMilkName);
  }
};
} // namespace coffee_shop::domain

#endif // SOYMILK_HPP
