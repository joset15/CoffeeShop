#ifndef LEMON_HPP
#define LEMON_HPP
#pragma once

#include "IngredientDecorator.hpp"

#include <string>
#include <string_view>

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

#endif // LEMON_HPP
