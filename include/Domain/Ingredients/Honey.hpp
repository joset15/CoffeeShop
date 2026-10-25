#ifndef HONEY_HPP
#define HONEY_HPP

#include "IngredientDecorator.hpp"

#include <string>
#include <string_view>

/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view HoneyName = "Honey";

class Honey : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(HoneyName);
  }
};

#endif // HONEY_HPP
